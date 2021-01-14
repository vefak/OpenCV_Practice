/*
 * Lesson 16-- Color Recognition by inRange 
 * 
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



int main(int argc, char* argv[])
{

	VideoCapture vid(0);
	if (!vid.isOpened()) {
		cout << "ERROR! Unable to open camera\n" << endl;
		return -1;
	}

	namedWindow("Control", CV_MAJOR_VERSION);
	
	// These are HSV color space parameters
	// Some colors are detected in HSV is better
	// H: Hue
	// S: Saturation
	// V: Value
	// Tune values from trackbar to find desired color
	int Hmindeg = 110;
	int Hmaxdeg = 130;

	int Smindeg = 50;
	int Smaxdeg = 255;

	int Vmindeg = 50;
	int Vmaxdeg = 255;

	// Create trackbars for all parameters 
	createTrackbar("minH", "Control", &Hmindeg, 179);
	createTrackbar("maxH", "Control", &Hmaxdeg, 179);

	createTrackbar("minS", "Control", &Smindeg, 255);
	createTrackbar("maxS", "Control", &Smaxdeg, 255);

	createTrackbar("minV", "Control", &Vmindeg, 255);
	createTrackbar("maxV", "Control", &Vmaxdeg, 255);

	// Variable to track color coordinates
	int pre_x = -1;
	int pre_y = -1;

	Mat tempframe;
	vid.read(tempframe); // Get single frame
	Mat drawframe = Mat::zeros(tempframe.size(), CV_8UC3);
	
	while (1)
	{
		Mat mainframe;
		bool bSuccess = vid.read(mainframe); 
		// Check frames asset
		if (!bSuccess)
		{
			cout << "ERROR! Unable to get new frame\n" << endl;
			break;
			}

		Mat HSVres;
		cvtColor(mainframe, HSVres, COLOR_BGR2HSV); // COnvert frame to HSV from RGB 
		Mat isres;
		
		// Apply color filtering 
		inRange(HSVres, Scalar(Hmindeg, Smindeg, Vmindeg), Scalar(Hmaxdeg, Smaxdeg, Vmaxdeg), isres);

		// Do some morphological operations to get more smooth shapes
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		// Calculates all of the moments up to the third order of a polygon or rasterized shape.
		// The function computes moments, up to the 3rd order, of a vector shape or a rasterized shape
		Moments location_shape = moments(isres);
		
		// By moments we can find center of shape and its size
		double y_axis = location_shape.m01;
		double x_axis = location_shape.m10;
		double area = location_shape.m00;

		if (area > 1000) // ignore small ares
		{	
			// New coordinates
			int next_x = x_axis / area;
			int next_y = y_axis / area;

			// Draw line
			if (pre_x >= 0 && pre_y >= 0 && next_x >= 0 && next_y >= 0)
			{
				line(drawframe, Point(next_x, next_y), Point(pre_x, pre_y), Scalar(0, 0, 255), 2);
			}
			pre_x = next_x;
			pre_y = next_y;
		}

		imshow("Black&White Image", isres);
		mainframe = mainframe + drawframe;
		imshow("Orjinal", mainframe);

		if (waitKey(30) == 27){
			break;
		}


	}
	destroyAllWindows();
	return 0;
}





