/*
 * Lesson 7 -- Adjust Contrast of Image Brightness
 * This example shows how to change contrast of image
 * Author: Vefak Murat Akman
 *  
 */

// Import libraries
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat res = imread("/home/makman4/dog.jpeg");
	
	int height = res.size().height;
	int width = res.size().width;

	if (res.empty()){
		cout << "ERROR! Unable to open image" << endl;
		return -1;
	}
	

	/*

	cv::Mat::convertTo	(OutputArray m, int rtype, double alpha = 1, double beta = 0)
	
	m	output matrix; if it does not have a proper size or type before the operation, it is reallocated.

	rtype	desired output matrix type or, rather, the depth since the number of channels are the same as 
	the input has; if rtype is negative, the output matrix will have the same type as the input.

	alpha	optional scale factor.

	beta	optional delta added to the scaled values.
	*/

	// Set contrast parameters
	// High alpha value => high contrast
	double alpha1 = 4.0;
	double alpha2 = 0.1;
	double beta   = 0.0;
	int rtype = -1;
	Mat res1;
	Mat res2;
	// Change contrast of images
	res.convertTo(res1, rtype, alpha1, beta);
	res.convertTo(res2, rtype, alpha2, beta);

	namedWindow("Orginal", CV_MINOR_VERSION);
	moveWindow("Orginal", 20,20); 
	namedWindow("Low Contrast", CV_MINOR_VERSION);
	moveWindow("Low Contrast", width+50,20);
	namedWindow("High Contrast", CV_MINOR_VERSION);
	moveWindow("High Contrast",width*2+100,20);

	imshow("High Contrast", res1);
	imshow("Low Contrast", res2);
	imshow("Orginal", res);

	waitKey(0);
	destroyAllWindows();
	return 0;
}