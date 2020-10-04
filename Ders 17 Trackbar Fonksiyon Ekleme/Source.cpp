#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat res;

void parfonk(int pardeg, void *userData)
{
	Mat isres;
	int zitdeg = *(static_cast<int*>(userData)); 
	int aydinlik = pardeg - 50;
	double zitlik = zitdeg / 50.0;
	cout << "parfonk : Contrast= " << zitlik << ", Parlaklik" << aydinlik << endl;
	res.convertTo(isres, -1, zitlik, aydinlik);
	imshow("degisen resim", isres);
}
void consfonk(int zitdeg, void *userData)
{
	Mat isres;
	int pardeg = *(static_cast<int*>(userData));
	int aydinlik = pardeg - 50;
	double zitlik = zitdeg / 50.0;
	cout << "consfonk : Contrast= " << zitlik << ", Parlaklik" << aydinlik << endl;
	res.convertTo(isres, -1, zitlik, aydinlik);
	imshow("degisen resim", isres);
}
int main(int argc, char** argv)
{
	res = imread("C:/Users/vmakm/Desktop/fries.jpg");
	namedWindow("degisen resim", CV_WINDOW_AUTOSIZE);
	int pardeg = 50;
	int zitdeg = 50;

	createTrackbar("Brightness", "degisen resim", &pardeg, 100, parfonk, &zitdeg);
	createTrackbar("Contrast", "degisen resim", &zitdeg, 100, consfonk, &pardeg);

	imshow("degisen resim", res);
	waitKey(0);
	return 0;
}





