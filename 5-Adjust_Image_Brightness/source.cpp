/*
 * Lesson 5 -- Adjust Image Brightness
 * This example shows how to increase&decrease brightness of image.
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
	Mat res = imread("./img/dog.jpeg");
	// Get size of input image
	int height = res.size().height;
	int width = res.size().width;
	// Check image asset
	if (res.empty()){
		cout << "ERROR! Unable to open image " << endl;
		return -1;
	}
	
	Mat res1 = res + Scalar(75, 75, 75); // Increase pixel value to bright image
	Mat res2 = res - Scalar(75, 75, 75); // Decrease pixel value to dark image

	namedWindow("Orginal", CV_MINOR_VERSION);
	moveWindow("Orginal", 20,20);  // Adjust position of window on screen
	namedWindow("Darker", CV_MINOR_VERSION);
	moveWindow("Darker", width+50,20);
	namedWindow("Brighter", CV_MINOR_VERSION);
	moveWindow("Brighter",width*2+100,20);

	imshow("Brighter", res1);
	imshow("Darker", res2);
	imshow("Orginal", res);
	
	waitKey(0); //wait until a keypress
	destroyAllWindows();
	
	return 0;
}