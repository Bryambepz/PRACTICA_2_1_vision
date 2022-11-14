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
Mat imgResta;
Mat imgClahe;
Mat imgConcatenadas;
Mat imgGrayClahe;
Mat imgMovimientoClahe;
Mat imgRestaClahe;
Mat imgGray;
Mat restaBlanco;
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
        Ptr<CLAHE> clahe = createCLAHE();

        namedWindow("videos", WINDOW_AUTOSIZE);

        while (3 == 3)
        {
            if(fps==0){
                t_init = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
            }
            fps++;

            video >> imgOriginal;

            flip(imgOriginal, imgOriginal, 1);

            cvtColor(imgOriginal, imgGray, COLOR_BGR2GRAY);

            if (imgMovimiento.empty())
            {
                imgMovimiento = imgGray.clone();
            }

            absdiff(imgGray, imgMovimiento, imgResta);
            imgMovimientoClahe = detectarZonas(imgResta, &area);

            clahe -> apply(imgGray, imgGrayClahe);
            // clahe -> apply(imgMovimientoClahe, imgMovimientoClahe);
            absdiff(imgGrayClahe, imgMovimientoClahe, imgRestaClahe);

            imgMovimiento = imgGray.clone();


            cvtColor(imgResta, imgResta, COLOR_GRAY2BGR);
            cvtColor(imgRestaClahe, imgRestaClahe, COLOR_GRAY2BGR);

            string Sarea = "Area: " + to_string(area);
            auto t_fin = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
            putText(imgOriginal,S_fps,Point(40,40),FONT_HERSHEY_PLAIN,2,Scalar(255,0,0),2);
            putText(imgOriginal,Sarea,Point(40,100),FONT_HERSHEY_PLAIN,2,Scalar(255,0,0),2);
            putText(imgOriginal,"Original",Point(40,imgOriginal.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(255,0,0),2);
            putText(imgResta,"Resta Movimiento",Point(40,imgResta.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(0,0,255),2);
            putText(imgRestaClahe,"Img Clahe",Point(40,imgRestaClahe.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(255,255,0),2);

            vector<Mat> imgs_concat = { imgOriginal, imgResta,imgRestaClahe};
            cv::hconcat(imgs_concat, imgConcatenadas);


            if((t_fin - t_init) >= 1){
                S_fps = "Fps: " + to_string(fps);
                fps = 0;
            }

            imshow("videos", imgConcatenadas);


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