# include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	VideoCapture vid("D:/videom.avi");
	if (!vid.isOpened()) {
		cout << "video yüklenmedi" << endl;
		system("pause");

	}
	namedWindow("acik", CV_WINDOW_AUTOSIZE);
	namedWindow("kapali", CV_WINDOW_AUTOSIZE);
	namedWindow("kendi", CV_WINDOW_AUTOSIZE);

	int satir = vid.get(CV_CAP_PROP_FRAME_HEIGHT);
	int sutun = vid.get(CV_CAP_PROP_FRAME_WIDTH);
	Size boyut(sutun, satir);

	VideoWriter vid2("D:/acik.avi", CV_FOURCC('M','P','4', '2'), 20, boyut, true);
	VideoWriter vid3("D:/kapali.avi", CV_FOURCC('M', 'P', '4', '2'), 20, boyut, true);
	
	while (1)  // frame nerede atama yapýyorr???
	{
		Mat frame;
		bool kontrol = vid.read(frame);
		if (!kontrol)
		{
			cout << " yeni frame gelmedi" << endl;
			waitKey(0);
			break;
		}
		imshow("kendi", frame);
		Mat frame1 = frame + Scalar(75, 75, 75);
		imshow("acik", frame1);
		vid2.write(frame1);
		Mat frame2 = frame - Scalar(75, 75, 75);
		imshow("kapali", frame2);
		vid3.write(frame2);
		
		waitKey(0);
		system("PAUSE");
		break;

	}
	return 0;
}
