/*
 * Lesson 12-- Trackbar
 * OpenCV provides some GUI utilities (highgui.hpp)
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
// Variables to use in trackbar
int bright = 50;
int contrast = 50;

int main(int argc, char* argv[])
{
	Mat res = imread("/home/makman4/dog.jpeg");
	
	// Variables to use in trackbar
	int bright = 50;
	int contrast = 50;

	namedWindow("Image", CV_MINOR_VERSION);

	/* int cv::createTrackbar	(	const String & 	trackbarname,
									const String & 	winname,
									int * 	value,
									int 	count,
									TrackbarCallback 	onChange = 0,
									void * 	userdata = 0 )	
	trackbarname	Name of the created trackbar.
	winname	Name of the window that will be used as a parent of the created trackbar.
	value	Optional pointer to an integer variable whose value reflects the position of the slider. Upon creation, the slider position is defined by this variable.
	count	Maximal position of the slider. The minimal position is always 0.
	onChange	Pointer to the function to be called every time the slider changes position. This function should be prototyped as void Foo(int,void*); , where the first parameter is the trackbar position and the second parameter is the user data (see the next parameter). If the callback is the NULL pointer, no callbacks are called, but only value is updated.
	userdata	User data that is passed as is to the callback. It can be used to handle trackbar events without using global variables.
	*/
	createTrackbar("Brightness", "Image", &bright, 250);
	createTrackbar("Contrast", "Image", &contrast, 250);

	while (1)
	{
		Mat isres;

		// When trackbar changes, bright and contrast values will change.
		// We need do new calculation everytime 
		int _bright = bright - 50; //Calculate the value using new value from trackbar
		double _contrast = contrast / 50.0; //Calculate the value using new value from trackbar

		// Using convertTo function from previous lesson
		res.convertTo(isres, -1, _contrast, _bright); // Multiple with _contrast, Adding with _bright
 		imshow("Image", isres); // Show image
		
		// Press ESC to break lopp
		if (waitKey(50) == 27){
			break;
		}
		
	}
	destroyAllWindows();
	return 0;
}




