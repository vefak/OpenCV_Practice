
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main(int argc, char* []) // char vs onlar� sor?
{
	VideoCapture vid(0);
	if (!vid.isOpened())
	{
		cout << "kamera yuklenemedi" << endl;
		system("Pause");
		return -1;

	}
	vid.set(CAP_PROP_POS_MSEC, 300); // NEDEN 0.3 SN SONRA BASLATTIK
	
	namedWindow("webcam", CV_MINOR_VERSION);
	while (1)
	{
		Mat Frame;
		bool kont = vid.read(Frame);
		if (!kont) // nas�l anl�yor ?? 
		{
			cout << "webcam frame y�klenmedi" << endl;
			break;
		}
		imshow("Bu Video", Frame);
		if (waitKey(1) == 27)
		{
			cout << "esc ile cikiss yaptiniz" << endl;
			break;
		}
	}
	system("Pause");
	return 0;
}
