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

//Variables
Mat imgOriginal;
Mat imgRuido;
Mat imgMediana;
Mat imgBlur;
Mat imgGaussiano;
Mat imgLaplacian;
Mat imgSobelX;
Mat imgSobelY;
Mat imgSobel;

Mat imgArriba;
Mat imgAbajo;
Mat imgConcat;

int porc = 0;
int tipo = 0;
int kernel = 1;

// Metodoss
void eventoTrack(int v, void *data){

}

void ruido(){
    int total = ((imgRuido.rows * imgRuido.cols) * porc) * 0.01;
    int col = 0, row = 0;
    int v = 0;
    for (int i = 0; i < total; i++)
    {
        if(tipo != 0){
            row = rand() % imgRuido.rows;
            col = rand() % imgRuido.cols;
        }
        if(tipo == 1){
            v = 255;
        }else if(tipo == 2){
            v = 0;
        }
        imgRuido.at<Vec3b>(row,col)[0] = v;
        imgRuido.at<Vec3b>(row,col)[1] = v;
        imgRuido.at<Vec3b>(row,col)[2] = v;
    }
}

void filtros(){

    if(kernel == 2){
        kernel = 3;
    }else if( kernel ==  3){
        kernel = 5;
    }else if( kernel == 4){
        kernel = 7;
    }else{
        kernel = 1;
    }
    medianBlur(imgRuido,imgMediana,kernel);
    blur(imgRuido,imgBlur,Size(kernel,kernel));
    GaussianBlur(imgRuido, imgGaussiano, Size(kernel,kernel), 1.73, 1.73);

    Laplacian(imgRuido, imgLaplacian ,-1,CV_16S);
    // cv::cvtColor(imgRuido, imgRuido, COLOR_BGR2GRAY);
    cv::Sobel(imgRuido, imgSobelX, CV_16S,1,0, -1);
    cv::convertScaleAbs(imgSobelX, imgSobelX, 1.0,0);
    cv::Sobel(imgRuido, imgSobelY, CV_16S, 0,1, -1);
    cv::convertScaleAbs(imgSobelY, imgSobelY, 1.0,0);
    cv::addWeighted(imgSobelX, 0.5, imgSobelY, 0.5,0,imgSobel);

    putText(imgMediana,"Mediana",Point(40,imgMediana.rows-40),0,1,Scalar(255,255,0),2);
    putText(imgBlur,"Blur",Point(40,imgBlur.rows-40),0,1,Scalar(255,255,0),2);
    putText(imgGaussiano,"Gaussiana",Point(40,imgGaussiano.rows-40),0,1,Scalar(255,255,0),2);
    putText(imgLaplacian,"D. Borde Laplacian",Point(40,imgLaplacian.rows-40),0,1,Scalar(255,255,0),2);
    putText(imgSobel,"D. Borde Sobel",Point(40,imgSobel.rows-40),0,1,Scalar(255,255,0),2);
}

int main()
{

    VideoCapture video(0);

    if (video.isOpened())
    {
        namedWindow("imgOriginal", WINDOW_AUTOSIZE);
        namedWindow("imagenes", WINDOW_AUTOSIZE);
        createTrackbar("Tipo Ruido", "imagenes", &tipo, 2, eventoTrack,NULL);
        createTrackbar("% Ruido", "imagenes", &porc, 100, eventoTrack,NULL);
        createTrackbar("Mascara", "imagenes", &kernel, 5, eventoTrack,NULL);

        while (3 == 3)
        {
            video >> imgOriginal;
            resize(imgOriginal,imgOriginal,Size(),0.6,0.6);
            flip(imgOriginal, imgOriginal, 1);
            imgRuido = imgOriginal.clone();
            
            ruido();
            filtros();
            vector<Mat> arriba = {imgRuido, imgMediana, imgBlur};
            cv::hconcat(arriba, imgArriba);
            vector<Mat> abajo = {imgGaussiano, imgLaplacian, imgSobel};
            cv::hconcat(abajo, imgAbajo);
            vector<Mat> imgConc = {imgArriba, imgAbajo};
            cv::vconcat(imgConc, imgConcat);

            imshow("imgOriginal", imgOriginal);
            imshow("imagenes", imgConcat);
            if (waitKey(23) == 27)
            {
                break;
            }
        }

        video.release();
        destroyAllWindows();
    }
    destroyAllWindows();
    return 0;
}