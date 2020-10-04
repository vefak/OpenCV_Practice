
#include <opencv2\opencv.hpp>
#include "iostream"

using namespace std;
using namespace cv;

int _tmain(int argc, char * argv[])
{
	VideoCapture vid(0);
	if (!vid.isOpened())
	{
		cout << "webcam yuklenmedi" << endl;
		system("Pause");
		return -1;
	}

	Mat yeni, eski, frame;
	vector<Point2f> enokta, ynokta; //eski ve yeni noktalar
	vector<uchar> durum; //nokta var mý yok mu
	vector<float> hata; //hesaplama hatasý
	enokta.push_back(Point(320, 240)); //ilk noktanýn yeri
	vid >> frame;
	cvtColor(frame, yeni, CV_BGR2GRAY);

	while (true)
	{
		eski = yeni.clone(); //hata vermesin diye clone kullanýldý. 
		vid >> frame;
		cvtColor(frame, yeni, CV_BGR2GRAY);
		calcOpticalFlowPyrLK(eski, yeni, enokta, ynokta, durum, hata); //eski resimdeki noktayý yeni resimde arar
		line(frame, ynokta[0], ynokta[0], Scalar(255, 255, 255), 3, 8, 0);
		imshow("deneme", frame);
		enokta[0] = ynokta[0]; //yeni bulunan noktayý eski yapar.

		if (durum[0] == 1)
		{
			cout << "nokta var" << endl;
		}
		else
			cout << "nokta yok" << endl;

		if (waitKey(30) == 27)
		{
			break;
		}
	}
	return 0;
}

