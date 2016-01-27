 #include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "highgui.h"
using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
     Mat img(650, 600, CV_16UC3, Scalar(50000,0,0)); //twozenie obrazu ( 3 kanaly, 16 bitowy, roz 650x600 ,RGB 

     if (img.empty()) //sprawdzanie czy zaladowano obraz
     {
          cout << "Blad nie mozna wczytac obrazka!" << endl;
          //kom  bledu  jezeli nie-zalad obraz
          return -1;
     }

     vector<int> compression_params; //vector przechowujacy parametry kompresji obrazu

     compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //kompresja obrazu jpg

     compression_params.push_back(71); //jakosc kompesji



     bool bSuccess = imwrite("TestObrazek.jpg", img, compression_params); //zapis obrazu do pliku



     if ( !bSuccess )

    {

         cout << "Blad obraz ie moze byc zaladowany" << endl;

        

    }

     namedWindow("Obrazek", CV_WINDOW_AUTOSIZE); //nowe okno
     imshow("Obrazek", img); //wyswietlanie obrazu

     waitKey(0);  //oczekiwanie na klawisz wyjscia

     destroyWindow("Obrazek"); //niszenie okna

     return 0;
}
