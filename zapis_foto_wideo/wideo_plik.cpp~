#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "highgui.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap("SampleVideo.avi"); 
    if ( !cap.isOpened() )  
         cout << "Nie mozna odczytac wideo" << endl;
         return -1;
    }

    

    double fps = cap.get(CV_CAP_PROP_FPS); 

     cout << "Klatka sekunda " << fps << endl;

    namedWindow("Video",CV_WINDOW_AUTOSIZE); 

    while(1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); 

        if (!bSuccess) 
        {
                        cout << "Blad nie mona odczytacramki z video " << endl;
                       break;
        }

        imshow("MyVideo", frame); 
        if(waitKey(30) == 27) 
       {
                cout << "esc koniec" << endl; 
                break; 
       }
    }

    return 0;

}
