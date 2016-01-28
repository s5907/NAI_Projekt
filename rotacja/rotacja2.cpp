#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "highgui.h"
using namespace cv;

int iAngle = 180;
int iScale = 50;
int iBorderMode = 0;
Mat imgOriginal ;
int iImageCenterY = 0;
int iImageCenterX = 0;
const char* pzRotatedImage = "Rotacja Obrazka";

void CallbackForTrackBar(int, void*)
{
 Mat matRotation = getRotationMatrix2D(  Point( iImageCenterX, iImageCenterY ), (iAngle - 180), iScale / 50.0 );
 
 // Rotacja Obrazka
 Mat imgRotated;
 warpAffine( imgOriginal, imgRotated, matRotation, imgOriginal.size(), INTER_LINEAR, iBorderMode, Scalar() );

 imshow( pzRotatedImage, imgRotated );
 
}

 int main( int argc, char** argv )
 {
 // Wczytywanie obrazka
 imgOriginal = imread( "foto.jpg", 1 );

 iImageCenterY = imgOriginal.rows / 2;
 iImageCenterX = imgOriginal.cols / 2;

 //wyswietlanie orginalnego obrazka
 const char* pzOriginalImage = "Foto";
 namedWindow( pzOriginalImage, CV_WINDOW_AUTOSIZE );
 imshow( pzOriginalImage, imgOriginal );

 //Trprzenie okna rotacji i przetwazania obrazka
 namedWindow( pzRotatedImage, CV_WINDOW_AUTOSIZE );
 createTrackbar("kat obrotu", pzRotatedImage, &iAngle, 360, CallbackForTrackBar);
 createTrackbar("skalowanie", pzRotatedImage, &iScale, 100, CallbackForTrackBar);
 createTrackbar("granica obrotu", pzRotatedImage, &iBorderMode, 5, CallbackForTrackBar);
 
 int iDummy = 0;

 CallbackForTrackBar(iDummy, &iDummy);

 waitKey(0);

 return 0;
}
