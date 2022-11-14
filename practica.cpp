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
int fps = 0;
int main()
{

    auto t_init = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
    Mat imgGray;
    string S_fps;
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
            
            clahe -> apply(imgGray, imgGrayClahe);
            clahe -> apply(imgMovimiento, imgMovimientoClahe);
            absdiff(imgGrayClahe, imgMovimientoClahe, imgRestaClahe);

            imgMovimiento = imgGray.clone();

            cvtColor(imgResta, imgResta, COLOR_GRAY2BGR);
            cvtColor(imgRestaClahe, imgRestaClahe, COLOR_GRAY2BGR);

            auto t_fin = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
            putText(imgOriginal,S_fps,Point(40,40),FONT_HERSHEY_PLAIN,2,Scalar(255,255,0),2);
            putText(imgOriginal,"Img Original",Point(40,imgOriginal.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(255,255,0),2);
            putText(imgResta,"Resta Movimiento",Point(40,imgResta.rows-40),FONT_HERSHEY_PLAIN,2,Scalar(255,255,0),2);

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