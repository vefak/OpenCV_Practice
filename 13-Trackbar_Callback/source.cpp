/*
 * Lesson 13-- Trackbar Callback Functions
 * The callback function is called every time the user moves the slider.
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

// Global Mat variable to acces from all methods
Mat res;

// First callback to adjust brightness
void brightnessCallback(int brtval, void *userData)
{
	Mat isres;
	// Implement new values. Contrast remains same
	int contval = *(static_cast<int*>(userData)); 
	int bright = brtval - 50;
	double contrast = contval / 50.0;
	//Print out current values. While brightness is chaning, contrast remains same
	cout << "brightnessCallback : Contrast= " << contrast << ", Brightness" << bright << endl;
	res.convertTo(isres, -1, contrast, bright);
	imshow("Image", isres);
}

// Second callback to adjust contrast
void contrastCallback(int contval, void *userData)
{
	Mat isres;
	// Implement new values. Brightness remains same
	int brtval = *(static_cast<int*>(userData));
	int bright = brtval - 50;
	double contrast = contval / 50.0;
	//Print out current values. While contrast is chaning, brightness remains same
	cout << "contrastCallback : Contrast= " << contrast << ", Brightness" << bright << endl;
	res.convertTo(isres, -1, contrast, bright);
	imshow("Image", isres);
}
int main(int argc, char** argv)
{
	res = imread("/home/makman4/dog.jpeg");
	namedWindow("Image", CV_MINOR_VERSION);

	int brtval = 50;
	int contval = 50;
	// Pointers are used to access values at trackbars
	createTrackbar("Brightness", "Image", &brtval, 100, brightnessCallback, &contval);
	createTrackbar("Contrast", "Image", &contval, 100, contrastCallback, &brtval);
	imshow("Image", res);

	waitKey(0);
	return 0;
}





