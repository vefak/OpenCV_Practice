

// murat murat
//



#include <opencv2\opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat res(720, 1280, CV_8UC3, Scalar(10, 150, 40));
	if (res.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		system("pause"); //wait for a key press

		return -1; 
	}
	vector<int> sparam;
	sparam.push_back(CV_IMWRITE_PNG_COMPRESSION);
	sparam.push_back(7);

	bool kontrol = imwrite("D://resimresim.png", res, sparam);

	if (!kontrol)
	{
		cout << "Resim olmadý" << endl;
		system("Pause");

	}
	namedWindow("kaydedilen resim", CV_WINDOW_AUTOSIZE);
	imshow("kaydedilen resim", res);
	waitKey(0);
	destroyWindow("kaydedilen resim");
	return 0;
	 
}