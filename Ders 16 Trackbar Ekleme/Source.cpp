#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;




int main(int argc, char* argv[])
{
	Mat res = imread("C:/Users/vmakm/Desktop/fries.jpg");
	namedWindow("degisen resim", CV_WINDOW_AUTOSIZE);
	int aydinlik = 50;
	createTrackbar("Aydinlik", "degisen resim", &aydinlik, 100);
	int zitlik = 50;
	createTrackbar("Contrast", "degisen resim", &zitlik, 100);

	while (1)
	{
		Mat isres;
		int parlaklik = aydinlik - 50;
		double contr = zitlik / 50.0;
		res.convertTo(isres, -1, contr, parlaklik); // contr ile çarpýlýyor , parlaklik ile toplaniyor
 		imshow("degisen resim", isres);
		if (waitKey(50) == 27)
		{
			break;
			
		}
		
	}
	return 0;
}




