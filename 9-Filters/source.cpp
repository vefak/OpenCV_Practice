/*
 * Lesson 9-- Filters
 * Application of some basic smoothing filters
 * You can modify images by using this GUI
 * 
 * Author: Vefak Murat Akman
 *  
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat res = imread("/home/makman4/dog.jpeg");
	Mat _gauss,_median;
	
	int width = res.size().width;
	int sigmaX = 0.5; // For Gauss Bluring method
	
	namedWindow("Orginal", CV_MINOR_VERSION);
	moveWindow("Orginal", 20,100);  
	namedWindow("Blur", CV_MINOR_VERSION);
	moveWindow("Blur", width+50,100);
	namedWindow("Gaussian", CV_MINOR_VERSION);
	moveWindow("Gaussian", width*2+50,100);


	int i=3;
	while(i<21){

		Mat _gauss,_blur;
		// Gaussian smoothing filter
		GaussianBlur(res,_gauss,Size(i, i), sigmaX);	
		// Blur smoothing filter
		blur(res, _blur,Size(i, i));

		imshow("Orginal", res);
		imshow("Blur", _blur);
		imshow("Gaussian", _gauss);	

		i=i+2;
		waitKey(1000); //wait key to continue 
		// Press ESC to break lopp
		if (waitKey(0) == 27){
			break;
		}
	}

	destroyAllWindows();
	return 0;
}


