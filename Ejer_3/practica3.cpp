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
Mat imgErosion;
Mat imgDilatacion;
Mat imgTopHat;
Mat imgBlackHat;
Mat imgCombinacion;
Mat imgToraxComb;
Mat imgColumnaComb;
Mat imgCaderaCom;


// Metodoss
void oprecionMorfologica(Mat imgOrig){
    //
    Mat structuringElement = getStructuringElement(MORPH_CROSS,Size(25,25));

    morphologyEx(imgOrig, imgErosion, MORPH_ERODE, structuringElement, Point(-1,-1),2);
    putText(imgErosion,"Erosion",Point(40,imgErosion.rows-40),0,1,Scalar(255,255,0),1);

    morphologyEx(imgOrig, imgDilatacion, MORPH_DILATE, structuringElement, Point(-1,-1),2);
    putText(imgDilatacion,"Dilatacion",Point(40,imgDilatacion.rows-40),0,1,Scalar(255,255,0),1);

    morphologyEx(imgOrig, imgTopHat, MORPH_TOPHAT, structuringElement, Point(-1,-1),1);
    morphologyEx(imgOrig, imgBlackHat, MORPH_BLACKHAT, structuringElement, Point(-1,-1),1);

    absdiff(imgTopHat, imgBlackHat, imgCombinacion);
    addWeighted(imgOrig, 0.5, imgCombinacion, 0.5, 0, imgCombinacion);    
    
    putText(imgTopHat,"Top-Hat",Point(40,imgTopHat.rows-40),0,1,Scalar(255,255,0),1);
    putText(imgBlackHat,"Black-Hat",Point(40,imgBlackHat.rows-40),0,1,Scalar(255,255,0),1);
    putText(imgCombinacion,"Operacion",Point(40,imgBlackHat.rows-40),0,1,Scalar(255,255,0),1);
}   

int main()
{

    Mat imgTorax = imread("rx_torax.jpg", IMREAD_GRAYSCALE);
    resize(imgTorax, imgTorax, Size(), 0.5, 0.5);
    Mat imgColLumb = imread("columna_lumbar.jpeg", IMREAD_GRAYSCALE);
    Mat imgCadera = imread("rx_cadera.jpeg", IMREAD_GRAYSCALE);

    namedWindow("imgTorax", WINDOW_AUTOSIZE);
    namedWindow("imgColumna", WINDOW_AUTOSIZE);
    namedWindow("imgCadera", WINDOW_AUTOSIZE);

    oprecionMorfologica(imgTorax);
    vector<Mat> torax = {imgTorax, imgErosion, imgDilatacion, imgTopHat, imgBlackHat, imgCombinacion};
    cv::hconcat(torax, imgToraxComb);
    imshow("imgTorax", imgToraxComb);

    oprecionMorfologica(imgColLumb);
    vector<Mat> colum = {imgColLumb, imgErosion, imgDilatacion, imgTopHat, imgBlackHat, imgCombinacion};
    cv::hconcat(colum, imgColumnaComb);
    imshow("imgColumna", imgColumnaComb);

    oprecionMorfologica(imgCadera);
    vector<Mat> cadera = {imgCadera, imgErosion, imgDilatacion, imgTopHat, imgBlackHat, imgCombinacion};
    cv::hconcat(cadera, imgCaderaCom);
    imshow("imgCadera", imgCaderaCom);
    
    waitKey(0);
    destroyAllWindows();
    return 0;
}