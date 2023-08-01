#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <stdio.h>
#include <string>
#include <vector>
#include <ctime> // Dodaliśmy nagłówek ctime do obsługi czasu


using namespace std;
using namespace cv;

void scanPlates()
{
    Mat klatka;
    VideoCapture  capture(0);       // 0 dla telefonu a 1 dla pc 

    CascadeClassifier kaskadaPlates;
    kaskadaPlates.load("E:\\Programowanie\\ScanPlates\\Resources\\haarcascades\\data\\haarcascades\\haarcascade_plate_number.xml");  

    if(kaskadaPlates.empty()) {cout<< "Nie mozna załadowac kaskady, NOT Load XML" <<endl ;}

    vector<Rect> plates;

    while(true){

    capture.read(klatka);
    kaskadaPlates.detectMultiScale(klatka,plates, 1.1, 10);

    for(int i = 0; i < plates.size(); i++){
        Mat imgPrzytnij = klatka(plates[i]);

        time_t now = time(0);
        tm* ltm = localtime(&now);

        string filename = "E:\\Programowanie\\ScanPlates\\Resources\\Tablice\\" + 
        to_string(ltm->tm_hour) + ";" +
        to_string(ltm->tm_min) + ";" +
        to_string(ltm->tm_sec) + "_" +
        to_string(ltm ->tm_mday) +"." +
        to_string(1 + ltm->tm_mon) + "." +
        to_string(1900 + ltm->tm_year) +
        "_" + to_string(i)+".png";

        imwrite(filename, imgPrzytnij); //"E:\\Programowanie\\projekt-wizji\\Resources\\Tablice\\" 
        rectangle(klatka, plates[i].tl(), plates[i].br(), Scalar(255,0,255), 3);

    }
    imshow("Window1", klatka);
    if(waitKey(1) == 27) {break;}

    }

}