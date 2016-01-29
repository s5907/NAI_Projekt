#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "highgui.h"
using namespace cv;
using namespace std;

 int main( int argc, char** argv )
 {
    VideoCapture cap(0); //przechwytywanie obrazu zkamety

    if ( !cap.isOpened() )  // blad koniec
    {
         cout << "Nie mozna otwozyc kamery" << endl;
         return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //twozenie okna

 int iLowH = 0;
 int iHighH = 179;

 int iLowS = 0; 
 int iHighS = 255;

 int iLowV = 0;
 int iHighV = 255;

 
 cvCreateTrackbar("LowH", "Control", &iLowH, 179); 
 cvCreateTrackbar("HighH", "Control", &iHighH, 179);

 cvCreateTrackbar("LowS", "Control", &iLowS, 255);
 cvCreateTrackbar("HighS", "Control", &iHighS, 255);

 cvCreateTrackbar("LowV", "Control", &iLowV, 255); 
 cvCreateTrackbar("HighV", "Control", &iHighV, 255);

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // czytanienie poszczegolnych klatek

         if (!bSuccess) //jezeli blad wyjdz z petli
        {
             cout << "nie mozna odczytac strumienia wideo" << endl;
             break;
        }

  Mat imgHSV;

  cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //konwersja RBG do HSV
 
  Mat imgThresholded;

  inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Progowanie obrazu
      
  //przetwazanie obrazu erozja wyzucanie malych plam szumow z pierwszego planu
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

  //przetwazanie obraz wyzucanie malych dziur z pierwszego planu
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

  imshow("Thresholded Image", imgThresholded); //wyswietlanie progowanego obrazu
  imshow("Original", imgOriginal); //wyswietlanie orginalnego obrazu

        if (waitKey(30) == 27) //oczekiwanie na klawisz wyjscia zprogramu   
    {
            cout << "esc koniec programu" << endl;
            break; 
       }
    }

   return 0;

}
