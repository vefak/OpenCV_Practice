#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void mousekont(int event, int x, int y, int flags, void * kullanici)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Sol tiklandi, lokasyon:" << x << "x" << y << endl;
	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		cout << "Sag tiklandi, lokasyon:" << x << "x" << y << endl;
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		cout << "Orta buton tiklandi, lokasyon:" << x << "x" << y << endl;
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		cout << "hareket ediyor, lokasyon: " << x << "x" << y << endl;

	}
}

int main(int argc, char* argv[])
{
	Mat res = imread("C:/Users/vmakm/Desktop/fries.jpg");
	namedWindow("Mouse penceresi", CV_WINDOW_AUTOSIZE);
	setMouseCallback("Mouse penceresi", mousekont,NULL);
	imshow("Mouse penceresi", res);
	waitKey(0);
	return 0;
}





