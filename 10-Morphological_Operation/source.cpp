/*
 * Lesson 10-- Morphological Operation
 * Eroding
 * Dilating  
 * The most basic morphological operations are: Erosion and Dilation. They have a wide array of uses
 * 	Removing noise
 * 	Isolation of individual elements and joining disparate elements in an image.
 * 	Finding of intensity bumps or holes in an image
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
	Mat res = imread("./image.png");
	cvtColor(res, res, COLOR_BGR2GRAY); // Convert to gray

	// Create empty Mat variable to assign new filtered images
	Mat kernel;
	Mat ero, dil;

	// Get height and width of image
	int height = res.size().height;
	int width = res.size().width;

	namedWindow("Original", CV_MINOR_VERSION);
	namedWindow("Eroding", CV_MINOR_VERSION);
	namedWindow("Dilating", CV_MINOR_VERSION);


	
	/*
	void cv::erode	(	InputArray 	src,
						OutputArray 	dst,
						InputArray 	kernel,
						Point 	anchor = Point(-1,-1),
						int 	iterations = 1,
						int 	borderType = BORDER_CONSTANT,
						const Scalar & 	borderValue = morphologyDefaultBorderValue() )	

	void cv::dilate	(	InputArray 	src,
						OutputArray 	dst,
						InputArray 	kernel,
						Point 	anchor = Point(-1,-1),
						int 	iterations = 1,
						int 	borderType = BORDER_CONSTANT,
						const Scalar & 	borderValue = morphologyDefaultBorderValue())	
	*/
	
	kernel=Mat::ones(Size(3, 3), res.type()); // Erode&Dilate needs kernel filter to process. Here, 3x3 Kernel Matrix is created 

	erode(res, ero, kernel, Point(-1, -1), 2);
	dilate(res, dil, kernel, Point(-1, -1), 2);

	imshow("Original", res);
	imshow("Eroding", ero);
	imshow("Dilating", dil);

	waitKey(0);
	return(0);

}