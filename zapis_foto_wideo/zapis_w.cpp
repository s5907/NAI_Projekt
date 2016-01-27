 #include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "highgui.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap(0); // otweranie kamery wideo

    if (!cap.isOpened())  // wyjscie w razie niepowodzenia
    {
        cout << "ERROR: Cannot open the video file" << endl;
        return -1;
    }

 namedWindow("Wideo",CV_WINDOW_AUTOSIZE); //twozenie okna wideo
 
   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //pobieranie szerokosci klatek
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //pobieranie wysokosci kaltek

   cout << "Frame Size = " << dWidth << "x" << dHeight << endl;

   Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

 VideoWriter oVideoWriter ("wideo.avi", CV_FOURCC('P','I','M','1'), 20, frameSize, true); //twozenie obiektu VideoWriter  

   if ( !oVideoWriter.isOpened() ) //jezliWideoWriter nie dziala zakoncz
   {
        cout << "Blad nie mozna odczytac  wideo" << endl;
        return -1;
   }

    while (1)
    {
  
        Mat frame;

        bool bSuccess = cap.read(frame); // cztanie wideo po klatce

        if (!bSuccess) //jezeli blad opusc petle
       {
             cout << "Blad nie mozna odczytac kaltki wideo" << endl;
             break;
        }

        oVideoWriter.write(frame); //zapisz klatke do pliku

        imshow("Wideo", frame); //pokaz ramke w oknie

        if (waitKey(10) == 27) //czekaj na kalwisz wyjcia -opusc petle
       {
            cout << "esc wcisniety koniec" << endl;
            break; 
       }
    }

    return 0;

}
