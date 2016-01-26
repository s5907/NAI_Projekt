#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
          cout << "Lewy klawisz klikniety na pozycji (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "Prawy klawisz klikniety na pozycji (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "klawisz klikniety na pozycji (" << x << ", " << y << ")" << endl;
     }
     else if ( event == EVENT_MOUSEMOVE )
     {
          cout << "Mysz na pozycji (" << x << ", " << y << ")" << endl;

     }
}

int main(int argc, char** argv)
{
     
     Mat img = imread("foto.jpg");

   
     if ( img.empty() ) 
     { 
          cout << "Blod wczytywania zdjecia" << endl;
          return -1; 
     }

     //tworzenie okna
     namedWindow("Moje okno", 1);

     //funkcja zwraca pozycje myszy
     setMouseCallback("Moje okno", CallBackFunc, NULL);

     //wyswietlanie obrazka
     imshow("Moje okno", img);

     waitKey(0);

     return 0;

}


