// denemee.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	namedWindow("kontrol", CV_WINDOW_AUTOSIZE);

	int Hmindeg = 0;
	int Hmaxdeg = 245;

	int Smindeg =25;
	int Smaxdeg = 45;

	int Vmindeg = 200;
	int Vmaxdeg = 255;

	createTrackbar("minH", "kontrol", &Hmindeg, 255);
	createTrackbar("maxH", "kontrol", &Hmaxdeg, 255);

	createTrackbar("minS", "kontrol", &Smindeg, 255);
	createTrackbar("maxS", "kontrol", &Smaxdeg, 255);

	createTrackbar("MinV", "kontrol", &Vmindeg, 255);
	createTrackbar("MaxV", "kontrol", &Vmaxdeg, 255);

	int eskix = -1;
	int eskiy = -1;
	while (true)
	{
		Mat yeniframe = imread("C://Users/vmakm/Desktop/foto/12.jpg");

		Mat HSVres, sized;
		resize(yeniframe, sized, Size(640,480));
		cvtColor(sized, HSVres, COLOR_BGR2HSV);
		
		Mat isres;

		inRange(HSVres, Scalar(Hmindeg, Smindeg, Vmindeg), Scalar(Hmaxdeg, Smaxdeg, Vmaxdeg), isres);
		/*
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(20, 20)));
		*/
		imshow("Siyah Beyaz Resim", isres);
		imshow("Orjinal", sized);
		waitKey(33);
	}
	return 0;
}

