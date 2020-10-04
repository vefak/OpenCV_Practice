# include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	VideoCapture vid(0);
	if (!vid.isOpened()) {
		cout << "video yüklenmedi" << endl;
		system("pause");

	}
	namedWindow("webcam kayýt", CV_WINDOW_AUTOSIZE);
	int satir = vid.get(CV_CAP_PROP_FRAME_HEIGHT);
	int sutun = vid.get(CAP_PROP_FRAME_WIDTH);
	cout << "boyut: " << sutun << "*" << satir << endl;
	Size boyut(sutun, satir);
	VideoWriter yaz("D:/videom.avi", CV_FOURCC_DEFAULT, 20, boyut, true);
	if (!yaz.isOpened()) {
		cout << "video yüklenemedi" << endl;
		return -1;

	}
	while (1)  
	{
		Mat frame;
		bool kontrol = vid.read(frame);
		if (!kontrol)
		{
			cout << "webcamden yeni frame gelmedi" << endl;
			break;
		}
		yaz.write(frame);
		if (waitKey(30) == 27)
		{
			cout << "esc ile cikis yapildi" << endl;
			break;
		}

	}
	return 0;
}
