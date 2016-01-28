#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "highgui.h"
using namespace cv;

 int main( int argc, char** argv )
 {
     // wczytywanie obrazka
     Mat imgOriginal = imread( "foto.jpg", 1 );

     //wyswietlanie obazka
     const char* pzOriginalImage = "Foto";
     namedWindow( pzOriginalImage, CV_WINDOW_AUTOSIZE );
     imshow( pzOriginalImage, imgOriginal );

     const char* pzRotatedImage = "Foto Rotacja";
     namedWindow( pzRotatedImage, CV_WINDOW_AUTOSIZE );

     int iAngle = 180;
     createTrackbar("kat obrotu", pzRotatedImage, &iAngle, 360);

     int iImageHieght = imgOriginal.rows / 2;
     int iImageWidth = imgOriginal.cols / 2;

     while (true)
     {
          Mat matRotation = getRotationMatrix2D( Point(iImageWidth, iImageHieght), (iAngle - 180), 1 );
 
          // Rotajcja obrazka
          Mat imgRotated;
          warpAffine( imgOriginal, imgRotated, matRotation, imgOriginal.size() );

          imshow( pzRotatedImage, imgRotated );

          int iRet = waitKey(30);
          if ( iRet == 27 )
          {
               break;
          }
     }

     return 0;
}
