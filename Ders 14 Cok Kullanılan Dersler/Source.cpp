

#include <opencv2\opencv.hpp>


#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	namedWindow("kontrol", CV_WINDOW_AUTOSIZE);

	int Hmindeg = 30;
	int Hmaxdeg = 255;

	int Smindeg = 140;
	int Smaxdeg = 180;

	int Vmindeg = 85;
	int Vmaxdeg = 135;

	createTrackbar("minH", "kontrol", &Hmindeg, 255);
	createTrackbar("maxH", "kontrol", &Hmaxdeg, 255);

	createTrackbar("minS", "kontrol", &Smindeg, 255);
	createTrackbar("maxS", "kontrol", &Smaxdeg, 255);

	createTrackbar("MinV", "kontrol", &Vmindeg, 255);
	createTrackbar("MaxV", "kontrol", &Vmaxdeg, 255);

	
	while (true)
	{
		Mat yeniframe = imread("C://Users/vmakm/Desktop/RAPOR/parmaklar");

		Mat HSVres;
		cvtColor(yeniframe, HSVres, COLOR_BGR2Lab);
		Mat isres;

		inRange(HSVres, Scalar(Hmindeg, Smindeg, Vmindeg), Scalar(Hmaxdeg, Smaxdeg, Vmaxdeg), isres);

		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(20, 20)));

		imshow("Siyah Beyaz Resim", isres);
		imshow("Orjinal", yeniframe);
		waitKey(33);
	}
	return 0;
}

