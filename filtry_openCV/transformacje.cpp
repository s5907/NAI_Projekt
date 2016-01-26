#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;

int main()
{
        //wyswietlanie obrazka
        IplImage* img = cvLoadImage("foto.jpg");
        cvNamedWindow("Obrazek");
        cvShowImage("Obrazek", img);


             //praksztalcenie obrazka
        cvErode(img, img, 0, 2);
        cvNamedWindow("Erozja");
        cvShowImage("Erozja", img);
	cvDilate(img, img, 0, 2);
        cvNamedWindow("Rozmycie");
        cvShowImage("Rozmycie", img);   
	cvNot(img, img);
        cvNamedWindow("Odwrotny");
        cvShowImage("Odwrotny", img);

 cvWaitKey(0);

       
        cvDestroyWindow("Obrazek");
        cvDestroyWindow("Erozja");
	cvDestroyWindow("Rozmycie");
	cvDestroyWindow("Odwrotny");

        cvReleaseImage(&img);
		
  
        return 0;
}
