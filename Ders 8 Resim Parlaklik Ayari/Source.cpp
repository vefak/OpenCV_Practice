
// murat murat
//



#include <opencv2\opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat res = imread("C:/Users/vmakm/Desktop/isim.jpg");
	if (res.empty())
	{
		cout << "resim yuklenemedi" << endl;
		system("pause");
	}
	Mat res1 = res + Scalar(75, 75, 75);
	Mat res2 = res - Scalar(75, 75, 75);
	namedWindow("parlak", CV_WINDOW_AUTOSIZE);
	namedWindow("karanlik", CV_WINDOW_AUTOSIZE);
	namedWindow("orjinal", CV_WINDOW_AUTOSIZE);

	imshow("parlak", res1);
	imshow("karanlik", res2);
	imshow("orjinal", res);
	waitKey(0);
	destroyAllWindows();
	return 0;
}