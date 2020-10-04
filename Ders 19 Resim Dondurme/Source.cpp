#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main(int argc, char* argv[])
{
	Mat res = imread("C:/Users/vmakm/Desktop/fries.jpg");
	namedWindow("donen", CV_WINDOW_AUTOSIZE);
	int aci = 180;
	createTrackbar("Aci", "donen", &aci, 360);

	while (1)
	{
		Mat benmat = getRotationMatrix2D(Point(res.cols / 2, res.rows / 2), aci - 180, 1);
		Mat donres;
		warpAffine(res, donres, benmat, res.size());
		imshow("donen", donres);
		if (waitKey(50) == 27)
		{
			break;
		}
	}



	return 0;
}





