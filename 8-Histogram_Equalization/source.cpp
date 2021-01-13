/*
 * Lesson 8-- Histogram Equalization
 * Histogram is a graphical representation of the intensity distribution of an image.
 * It quantifies the number of pixels for each intensity value considered.
 * Histogram Equalization  is a method that improves the contrast in an image, in order to stretch out the intensity range.
 * 
 * Author: Vefak Murat Akman
 *  
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat res = imread("/home/makman4/dog.jpeg");
	int height = res.size().height;
	int width = res.size().width;

	if (res.empty()){
		cout << "ERROR! Unable to open image" << endl;
		return -1;
	}

	Mat gray;
	Mat ezhis;
	// cvtColor function enables to convert images different color spaces such Gray, LAB or RGB
	// In this example, image is convert to GRAY from RGB
	// Due to openCV represantation, RGB image is represented as BGR
	// cvtColor(src, dst, method)
	cvtColor(res, gray, COLOR_BGR2GRAY);
	
	// Histogram equalization
	// equalizeHist(src, dst) 
	equalizeHist(gray, ezhis);

	namedWindow("Orginal", CV_MINOR_VERSION);
	moveWindow("Orginal", 20,20); 
	namedWindow("Gray", CV_MINOR_VERSION);
	moveWindow("Gray", width+50,20);
	namedWindow("Equalized Histogram", CV_MINOR_VERSION);
	moveWindow("Equalized Histogram",width*2+100,20);

	imshow("Orginal", res);
	imshow("Gray", gray);
	imshow("Equalized Histogram", ezhis);

	waitKey(0);
	destroyAllWindows();
	return 0;

}