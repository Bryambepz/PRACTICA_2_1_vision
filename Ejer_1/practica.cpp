#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>

#include <opencv2/core.hpp>

// procesamiento y manipulacion de imagenes
#include <opencv2/imgproc.hpp>

// ventana y GUI
#include <opencv2/highgui.hpp>

// codecs y diferentes formatos de imagenes
#include <opencv2/imgcodecs.hpp>

// lectura de video
#include <opencv2/video.hpp>

// escritura de video
#include <opencv2/videoio.hpp>

#include <chrono>

// espacio de nombres de OpenCV
using namespace cv;
using namespace std;
using namespace std::chrono;

Mat imgOriginal;
Mat imgOriginalClahe;
Mat imgOriginalEqu;
Mat imgGray;
Mat imgGrayClahe;
Mat imgGrayEqu;
Mat imgResta;
Mat imgRestaNegada;
Mat imgRestaClahe;
Mat imgRestaEqu;

Mat imgConcatenadas;
Mat imgConcatenadas2;

Mat imgFiltro;
Mat imgFiltroResta;
string S_fps;
int fps = 0;
int area = 0;

Mat detectarZonas(Mat img, int *area){
    Mat zonas = Mat::zeros(img.size(), CV_8UC1);
    int pixel = 0;
    *(area) = 0;
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            pixel = img.at<uchar>(i,j);
            if(pixel>0){
                zonas.at<uchar>(i,j) = 255;
                *(area) = *(area)+1;
            }
        }
    }
    return zonas;
}

int main()
{

    auto t_init = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
    VideoCapture video(0);

    if (video.isOpened())
    {
        Mat imgMovimiento;
        Mat imgMovimientoClahe;
        Mat imgMovimientoEqu;
        Mat imgMovimientoFiltro;
        Ptr<CLAHE> clahe = createCLAHE();

        namedWindow("videos", WINDOW_AUTOSIZE);
        // namedWindow("filtro", WINDOW_AUTOSIZE);

        while (3 == 3)
        {
            if(fps==0){
                t_init = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
            }
            fps++;
           
            video >> imgOriginal;
            flip(imgOriginal, imgOriginal, 1);

            imgOriginalClahe = imgOriginal;

            imgOriginalEqu = imgOriginal;

            cvtColor(imgOriginal, imgGray, COLOR_BGR2GRAY);
            
            cvtColor(imgOriginalClahe, imgGrayClahe, COLOR_BGR2GRAY);
            clahe -> apply(imgGrayClahe, imgGrayClahe);

            cvtColor(imgOriginalEqu, imgGrayEqu, COLOR_BGR2GRAY);
            equalizeHist(imgGrayEqu, imgGrayEqu);
            
            cv::bilateralFilter(imgOriginal, imgFiltro, 15,100, 100);
            cvtColor(imgFiltro, imgFiltro, COLOR_BGR2GRAY);
            clahe ->apply(imgFiltro, imgFiltro);

            if (imgMovimiento.empty())
            {
                imgMovimiento = imgGray.clone();
                imgMovimientoClahe = imgGrayClahe.clone();
                imgMovimientoEqu = imgGrayEqu.clone();
                imgMovimientoFiltro = imgFiltro.clone();
            }

            absdiff(imgGray, imgMovimiento, imgResta);
            imgRestaNegada = detectarZonas(imgResta, &area);
            
            absdiff(imgGrayClahe, imgMovimientoClahe, imgRestaClahe);

            absdiff(imgGrayEqu, imgMovimientoEqu, imgRestaEqu);

            absdiff(imgFiltro, imgMovimientoFiltro, imgFiltroResta);
            int areaF = 0;

            // imgFiltroResta = detectarZonas(imgFiltroResta, &areaF);

            string Sarea = "Area: " + to_string(area);

            imgMovimiento = imgGray.clone();
            imgMovimientoClahe = imgGrayClahe.clone();
            imgMovimientoEqu = imgGrayEqu.clone();
            imgMovimientoFiltro = imgFiltro.clone();

            cv::cvtColor(imgResta, imgResta, COLOR_GRAY2BGR);
            cv::cvtColor(imgRestaClahe, imgRestaClahe, COLOR_GRAY2BGR);
            cv::cvtColor(imgRestaEqu, imgRestaEqu, COLOR_GRAY2BGR);
            cv::cvtColor(imgRestaNegada, imgRestaNegada, COLOR_GRAY2BGR);
            cv::cvtColor(imgGray, imgGray, COLOR_GRAY2BGR);
            cv::cvtColor(imgFiltroResta, imgFiltroResta, COLOR_GRAY2BGR);

            auto t_fin = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
            putText(imgOriginal,S_fps,Point(40,40),FONT_HERSHEY_PLAIN,2,Scalar(255,0,0),2);
            putText(imgOriginal,Sarea,Point(40,100),FONT_HERSHEY_PLAIN,2,Scalar(255,0,0),2);
            putText(imgOriginal,"Original",Point(40,imgOriginal.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(255,0,0),2);
            putText(imgResta,"Resta Movimiento",Point(40,imgResta.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(0,0,255),2);
            putText(imgFiltroResta,"Resta Negada con Filtro",Point(40,imgResta.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(0,0,255),2);
            putText(imgRestaNegada,"Resta Negada",Point(40,imgResta.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(0,0,255),2);
            putText(imgRestaClahe,"Img Clahe",Point(40,imgRestaClahe.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(255,255,0),2);
            putText(imgRestaEqu,"Img Equalizada",Point(40,imgRestaEqu.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(255,255,0),2);

            vector<Mat> imgs_concat = { imgOriginal, imgRestaNegada, imgFiltroResta };
            cv::hconcat(imgs_concat, imgConcatenadas);
            vector<Mat> imgs_concat_b = {imgResta, imgRestaClahe, imgRestaEqu };
            cv::hconcat(imgs_concat_b, imgConcatenadas2);
            vector<Mat> vertical = { imgConcatenadas, imgConcatenadas2};
            cv::vconcat(vertical, imgConcatenadas2);

            if((t_fin - t_init) >= 1){
                S_fps = "Fps: " + to_string(fps);
                fps = 0;
            }

            imshow("videos", imgConcatenadas2);
            // imshow("filtro", imgFiltroResta);

            if (waitKey(23) == 27)
            {
                break;
            }
        }
        destroyAllWindows();
        video.release();
    }

    return 0;
}