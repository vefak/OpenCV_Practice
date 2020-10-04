
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat res = imread("C:/Users/vmakm/Desktop/fries.jpg");
	if (res.empty())
	{
		cout << "resim yüklenemedi." << endl;
		return -1;
	}
	Mat res1;
	cvtColor(res, res1, CV_BGR2GRAY);
	Mat eshis;
	equalizeHist(res1, eshis);
	
	namedWindow("Ana Resim", CV_WINDOW_AUTOSIZE);
	namedWindow("esit histogram", CV_WINDOW_AUTOSIZE);
	namedWindow("Resim", CV_WINDOW_AUTOSIZE);

	imshow("Ana Resim", res1);
	imshow("Resim", res);
	imshow("esit histogram", eshis);
	waitKey(0);
	destroyAllWindows();
	return 0;

}