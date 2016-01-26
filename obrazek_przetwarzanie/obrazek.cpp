#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
     // wczytaj obraz 
     Mat src = imread("foto.jpg");

     //blad wcztwyania obrazu
     if (!src.data) 
     { 
          cout << "nie moge wczytac obrazu" << endl;
          return -1; 
     }

     // twozenie okna
     namedWindow("Obrazek", 1);

     //suwaka jasniej
     int iSliderValue1 = 50;
     createTrackbar("rozjasnij", "Obrazek", &iSliderValue1, 100);

     //suwak kontrast
     int iSliderValue2 = 50;
     createTrackbar("kontrast", "Obrazek", &iSliderValue2, 100);

     while (true)
     {
          //zniana jasnosci i kontrastu
         Mat dst;
          int iBrightness  = iSliderValue1 - 50;
          double dContrast = iSliderValue2 / 50.0;
          src.convertTo(dst, -1, dContrast, iBrightness); 

         
          imshow("Obrazek", dst);

       
          int iKey = waitKey(50);

          // 'ESC' konczy progam
          if (iKey == 27)
          {
               break;
          }
     }

     return 0;
}
