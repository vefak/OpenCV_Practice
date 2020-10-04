

#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;




int main(int argc, char* argv[])
{
	Mat res = imread("C:/Users/vmakm/Desktop/fries.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	namedWindow("orjinal resim", CV_WINDOW_AUTOSIZE);
	namedWindow("asindirilmis resim", CV_WINDOW_AUTOSIZE);
	namedWindow("genisletilmis resim", CV_WINDOW_AUTOSIZE);

	threshold(res, res, 128, 255, CV_THRESH_BINARY);
	imshow("orjinal resim", res);

	Mat filtre;
	Mat asindir, genis;

	filtre=Mat::ones(Size(3, 3), res.type());
	erode(res, asindir, filtre, Point(-1, -1), 2, 0, Scalar(5, 55, 55));
	dilate(res, genis, filtre, Point(-1, -1), 2, 0, Scalar(255, 255, 255));


	imshow("asindirilmis resim", asindir);
	imshow("genisletilmis resim", genis);
	waitKey(0);
	return(0);

}