
/*
 * Lesson 2 -- Load Image
 * This example shows how to create an image
 * Author: Vefak Murat Akman
 *  
 */

#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{	
	// Create Mat img at size 480x640 and (B, G, R) color
	// You can get desired color by changing RGB values
	Mat img(480, 640, CV_8UC3, Scalar(0, 0, 255));

	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		return -1;
	}

	namedWindow("MyWindow", CV_MINOR_VERSION); //create a window 
	imshow("MyWindow", img); //display the image 

	waitKey(0); ////wait until a key press
	destroyWindow("MyWindow"); //destroy the window 

	return 0;
}
