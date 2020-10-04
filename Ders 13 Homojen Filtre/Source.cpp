#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;



int main(int argc, char* argv[])
{
	Mat res = imread("C:/Users/vmakm/Desktop/fries.jpg");

	namedWindow("Orjinal Resim", CV_WINDOW_AUTOSIZE);
	namedWindow("Filtrelenmiþ Resim", CV_WINDOW_AUTOSIZE);
	imshow("Orjinal Resim", res);


	Mat filtres;
	char arayazi[60];

	for (int i = 1; i < 27; i = i + 2)
	{
		_snprintf_s(arayazi, 60, "Filtre buyuklugu %d x %d dir", i, i);
		blur(res, filtres, Size(i, i));
		putText(filtres, arayazi, Point(25, 50), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
		imshow("Filtrelenmiþ Resim", filtres);
		if (waitKey(3000) == 27)
		{
			return  0;
		}
		filtres = Mat::zeros(res.size(), res.type());
		_snprintf_s(arayazi, 60, "Cikmak icin bir tusa basiniz");
		putText(filtres, "Cikmak icin bir tusa basiniz", Point(10, 200), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
		imshow("Filtrelenmis Resim", filtres);
		waitKey(0);
	}
}


