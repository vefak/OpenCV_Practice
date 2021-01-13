/*
 * Lesson 10-- Morphological Operation
 * Opening
 * Closing
 * Morphological Gradient
 * Top Hat
 * Black Hat
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
	Mat ero, dil,open,close, tophat, grad, blackhat,temp1,temp2;

	// Get height and width of image
	int height = res.size().height*3;
	int width = res.size().width*3;

	namedWindow("Original", CV_MINOR_VERSION);
	namedWindow("Opening", CV_MINOR_VERSION);
	namedWindow("Closing", CV_MINOR_VERSION);
	namedWindow("Morphological Gradient", CV_MINOR_VERSION);
	namedWindow("Top Hat", CV_MINOR_VERSION);
	namedWindow("Black Hat", CV_MINOR_VERSION);

	moveWindow("Original",width+120,20);
	moveWindow("Opening",width*2+120,20);
	moveWindow("Closing",width*3+120,20);
	moveWindow("Morphological Gradient",width+120,height+20);
	moveWindow("Top Hat",width*2+120,height+20);
	moveWindow("Black Hat",width*3+120,height+20);



	Mat element = getStructuringElement(MORPH_RECT, Size(3,3), Point(-1,-1));

	// Opening
	// It is obtained by the erosion of an image followed by a dilation.
	erode(res, ero, element, Point(-1, -1), 1);
	dilate(ero, open, element, Point(-1, -1), 1);

	// Closing
	// It is obtained by the dilation of an image followed by an erosion.
	dilate(res, dil, element, Point(-1, -1), 1);
	erode(dil, close, element, Point(-1, -1), 1);
	
	// Morphological Gradient
	// It is the difference between the dilation and the erosion of an image.
	grad = dil-ero;

	// Top hat
	// It is the difference between an input image and its opening
	tophat = res - open;

	// Black Hat
	// It is the difference between the closing and its input image
	blackhat = close - res;


	imshow("Original", res);
	imshow("Opening", open);
	imshow("Closing", close);
	imshow("Morphological Gradient", grad);
	imshow("Top Hat", tophat);
	imshow("Black Hat", blackhat);

	waitKey(0);
	return(0);

}