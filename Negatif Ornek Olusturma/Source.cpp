
#include <iostream>
#include <opencv2\opencv.hpp>
#include "conio.h"
#include<fstream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	VideoCapture vid(0);
	if (!vid.isOpened())
	{
		cout << "webcam yüklenemedi" << endl;
		waitKey();
	}
	int sayici, bekle = 0;
	cout << "Kaldiginiz negatif resim sayisini giriniz…" << endl;
	cin >> sayici;
	ofstream file;
	file.open("negatif2.txt", ios::app);
	vector<int> sparam;
	sparam.push_back(CV_IMWRITE_JPEG_QUALITY);
	sparam.push_back(50);
	char yazi[250]; // sayici ile sürekli deðiþen dosya yolunu klasöre ve txt dosyasýna yazabilmek için karakter dizisi gerekmektedir.
	
	
	while (true)
	{
		
		Mat frame;
		bool kont = vid.read(frame);
		if (!kont)
		{
			cout << "frame yuklenmedi" << endl;
		}
	

		if (bekle>10)
		{
			_snprintf_s(yazi, 250, "D:\\train\\img\\negatif\\%d.jpg", sayici);
			imwrite(yazi, frame, sparam);
			_snprintf_s(yazi, 250, "D:\\train\\img\\negatif\\%d.jpg", sayici);
			file << yazi << endl;
			sayici++;
		}
		imshow("Nesne olmasin.", frame);
		if (waitKey(450) == 27)
		{
			file.close();
			break;
		}
	}
	return 0;
}