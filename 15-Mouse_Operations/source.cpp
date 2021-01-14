/*
 * Lesson 15-- Mouse Events
 * 
 * OpenCV can detect mouse events on OpenCV windows
 * By using these events, we can perform some application on frames such as drawing a rectangle
 * 
 * Author: Vefak Murat Akman
 *  
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void mousecontrol(int event, int x, int y, int flags, void * kullanici)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Left button coordinates: " << x << "x" << y << endl;
	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		cout << "Right button coordinates: " << x << "x" << y << endl;
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		cout << "Middle button coordinates: " << x << "x" << y << endl;
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		cout << "Moving cursor coordinates: " << x << "x" << y << endl;

	}
}

int main(int argc, char* argv[])
{
	Mat res = imread("/home/makman4/dog.jpeg");
	namedWindow("Frame", CV_MINOR_VERSION);
	setMouseCallback("Frame", mousecontrol,NULL);
	imshow("Frame", res);
	waitKey(0);
	return 0;
}





