/*
 * Lesson 14-- Rotation
 * It is possible to rotate images in OpenCV
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
	namedWindow("Rotated", CV_MINOR_VERSION);
	moveWindow("Rotated",400,200);
	int deg = 180;
	// Trackbar is used for rotated image 
	createTrackbar("Degree", "Rotated", &deg, 360);

	while (1)
	{
		Mat rotmat = getRotationMatrix2D(Point(res.cols / 2, res.rows / 2), deg - 180, 1); //Calculates an affine matrix of 2D rotation.
		Mat rotres;
		warpAffine(res, rotres, rotmat, res.size()); // Applies an affine transformation to an image.
		imshow("Rotated", rotres);
		if (waitKey(50) == 27){
			break;
		}
	}

	destroyAllWindows();
	return 0;
}





