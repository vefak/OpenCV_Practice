
// murat murat
//


#include <opencv2\opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture vid("C://Users/vmakm/Desktop/malmuzkafa.mp4");
	if (!vid.isOpened())
	{
		cout << "video yok" << endl;

	}
	vid.set(CV_CAP_PROP_POS_MSEC, 3000); // NEDEN 3 SN SONRA BASLATTIK
	double fps = vid.get(CV_CAP_PROP_FPS);
	cout << "frame per second: " << fps << endl;
	namedWindow("Bu Video", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		Mat res; 
		bool bbasari = vid.read(res); // ????
		if (!bbasari) // nasýl anlýyor ?? 
		{
			cout << "yeni frame okunmadi" << endl;
			break;
		}
		imshow("Bu Video", res);
		if (waitKey(30) == 27)
		{
			cout << "esc ile cikis yaptiniz" << endl;
			break;
		}
	}
	system("Pause");
	return 0;
}