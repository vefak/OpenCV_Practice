#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;



int main(int argc, char* argv[])
{
	Mat res = imread("/home/makman4/dog.jpeg");
	int width = res.size().width;

	namedWindow("Orginal", CV_MINOR_VERSION);
	moveWindow("Orginal", 20,20);  
	imshow("Orjinal", res);
	namedWindow("Filtered", CV_MINOR_VERSION);
	moveWindow("Filtered", width+50,20);
	

	Mat filtres;
	char arayazi[60];

	for (int i = 1; i < 27; i = i + 2){
		blur(res, filtres, Size(i, i));
		imshow("Filtered", filtres);
		filtres = Mat::zeros(res.size(), res.type());
		waitKey(33);
		
	}
	waitKey(0);
}


