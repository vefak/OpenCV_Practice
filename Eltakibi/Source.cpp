#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
	CascadeClassifier nesne;
	nesne.load("cascade.xml");
	VideoCapture vid;
	vid.open(1);

	if (!vid.isOpened())
	{
		cout << "Webcam yuklenmedi" << endl;
	
		return -1;
	}

	Mat frame;
	Mat grires;
	namedWindow("algilanan", 1);

	while (true)
	{
		vid >> frame;
		cvtColor(frame, grires, CV_BGR2GRAY);
		equalizeHist(grires,grires);
		vector<Rect> nesvek;
		nesne.detectMultiScale(grires, nesvek, 1.1, 3, 0, Size(30,30));
		cout << "nesvek" << endl;
		
		for (int i = 0; i < nesvek.size(); i++)
		{
			
		Point pt1(nesvek[i].x + nesvek[i].width, nesvek[i].y + nesvek[i].height);
			Point pt2(nesvek[i].x, nesvek[i].y); 
		
			rectangle(frame, pt1, pt2, cvScalar(0, 255, 0), 1, 8, 0);
		}
		imshow("algilanan", frame);
		waitKey(33);

	}
	return 0;
}