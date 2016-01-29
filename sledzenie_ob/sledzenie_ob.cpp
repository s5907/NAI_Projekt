#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "highgui.h"
using namespace cv;
using namespace std;

 int main( int argc, char** argv )
 {
    VideoCapture cap(0); 

    if ( !cap.isOpened() )  
    {
         cout << "Nie mozna otwozyc kamerki" << endl;
         return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); 

 int iLowH = 170;
 int iHighH = 179;

 int iLowS = 150; 
 int iHighS = 255;

 int iLowV = 60;
 int iHighV = 255;

 //Create trackbars in "Control" window
 createTrackbar("LowH", "Control", &iLowH, 179); 
 createTrackbar("HighH", "Control", &iHighH, 179);

 createTrackbar("LowS", "Control", &iLowS, 255); 
 createTrackbar("HighS", "Control", &iHighS, 255);

 createTrackbar("LowV", "Control", &iLowV, 255);
 createTrackbar("HighV", "Control", &iHighV, 255);

 int iLastX = -1; 
 int iLastY = -1;

 //przechwytywanie obrazow z kamery
 Mat imgTmp;
 cap.read(imgTmp); 

 //Twozenie nie czarnego zdjecia ze stumienia kamerki
 Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;
 

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // czytanie kolejnej klatki ze strumienia



         if (!bSuccess) //balad wyjdz z petli
        {
             cout << "Nie mozna odczytac strumienia wideo" << endl;
             break;
        }

  Mat imgHSV;

  cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //przeksztalcanie klatek z przechwyconego strumienia z BGR do HSV
 
  Mat imgThresholded;

  inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //progowanie obrazu
      
  //progowanie obrazu usuwanie malych obiektow szumow na wejsciu
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

  //progowanie obrazu usuwanie dziur po poprzednim przetwarzaniu 
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

  //znajdowanie pozycji progowanego obrazu
  Moments oMoments = moments(imgThresholded);

  double dM01 = oMoments.m01;
  double dM10 = oMoments.m10;
  double dArea = oMoments.m00;

  // jezeli <= 10000, znaleziono obiekt
  if (dArea > 10000)
  {
   //pozycja znalezionego obiektu
   int posX = dM10 / dArea;
   int posY = dM01 / dArea;        
        
   if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
   {
    //rysowanie lini oznaczajacej ruch obiektu
    line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
   }

   iLastX = posX;
   iLastY = posY;
  }

  imshow("Progowany Obraz", imgThresholded); //wyswietlanie progowanego obiektu

  imgOriginal = imgOriginal + imgLines;
  imshow("Kamerka", imgOriginal); //wyswietlanie widoku kamerki

        if (waitKey(30) == 27) //klawisz zakonczenia programu
       {
            cout << "esc koniec programu" << endl;
            break; 
       }
    }

   return 0;
}
