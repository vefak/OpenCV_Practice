#include <opencv2\opencv.hpp>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;



int main(int argc, char* argv[])
{
	VideoCapture vid(0);
	if (!vid.isOpened())
	{
		cout << "webcam yuklenemedi" << endl;
		system("pause");
		return -1;
	}
	namedWindow("kontrol", CV_WINDOW_AUTOSIZE);

	int Hmindeg = 170;
	int Hmaxdeg = 179;

	int Smindeg = 150;
	int Smaxdeg = 255;

	int Vmindeg = 60;
	int Vmaxdeg = 255;


	createTrackbar("minH", "kontrol", &Hmindeg, 179);
	createTrackbar("maxH", "kontrol", &Hmaxdeg, 179);

	createTrackbar("minS", "kontrol", &Smindeg, 255);
	createTrackbar("maxS", "kontrol", &Smaxdeg, 255);

	createTrackbar("minV", "kontrol", &Vmindeg, 255);
	createTrackbar("maxV", "kontrol", &Vmaxdeg, 255);

	int eskix = -1;
	int eskiy = -1;

	Mat araframe;
	vid.read(araframe);
	Mat cizgiresim = Mat::zeros(araframe.size(), CV_8UC3);
	while (1)
	{
		Mat yeniframe;
		bool bSuccess = vid.read(yeniframe);
		if (!bSuccess)
		{
			cout << "Yeni frame yuklenemedi" << endl;
			system("pause");
			break;

		}
		Mat HSVres;
		cvtColor(yeniframe, HSVres, COLOR_BGR2HSV);
		Mat isres;

		inRange(HSVres, Scalar(Hmindeg, Smindeg, Vmindeg), Scalar(Hmaxdeg, Smaxdeg, Vmaxdeg), isres);

		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		Moments konum = moments(isres);

		double yeksen = konum.m01;
		double xeksen = konum.m10;
		double alan = konum.m00;

		if (alan > 10000)
		{
			int yenix = xeksen / alan;
			int yeniy = yeksen / alan;

			if (eskix >= 0 && eskiy >= 0 && yenix >= 0 && yeniy >= 0)
			{
				line(cizgiresim, Point(yenix, yeniy), Point(eskix, eskiy), Scalar(0, 0, 255), 2);
			}
			eskix = yenix;
			eskiy = yeniy;
		}
		imshow("Siyaz Beyaz Resim", isres);

		yeniframe = yeniframe + cizgiresim;
		imshow("Orjinal", yeniframe);

		if (waitKey(30) == 27)
		{
			cout << "Kullanici esc ile cikti" << endl;
			break;
		}


	}

	return 0;
}





