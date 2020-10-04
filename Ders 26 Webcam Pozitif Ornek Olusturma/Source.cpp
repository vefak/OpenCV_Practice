
#include <iostream>
#include "conio.h"
#include<fstream>
#include <string>
#include <opencv2\opencv.hpp>


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	VideoCapture vid(0);
	if (!vid.isOpened())
	{
		cout << "webcam y�klenemedi"<< endl;
		waitKey();
	}
	int sayici = 0;
	cout << "Devam eden pozitif resim sayi ismini giriniz�" << endl;
	cin >> sayici;
	namedWindow("Nesneyi ortaya g�sterin.", CV_WINDOW_AUTOSIZE);
	ofstream file;
	file.open("pozitif.txt", ios::app);
	Mat gec; //siyah arka plan i�in ge�ici mat de�i�keni
	vid.read(gec);
	Mat arka; //�zerine �izgi �izmek ve yaz� yazmak i�in kullan�lan de�i�ken.

	vector<int> sparam;
	sparam.push_back(CV_IMWRITE_JPEG_QUALITY);
	sparam.push_back(50);
	char yazi[250]; //y�zde d li terimleri yazabilmek i�in kullan�lan dizi 
	int bekle = 0; //ba�lad�ktan sonra geri say�c� i�in kullan�lan de�i�ken

	int genislik = 45;
	createTrackbar("Genislik", "Nesneyi ortaya g�sterin.", &genislik, 320);
	int yukseklik = 45;
	createTrackbar("Yukseklik", "Nesneyi ortaya g�sterin.", &yukseklik, 240);
	int xeks1 = 200, xeks2 = 440, yeks1 = 120, yeks2 = 360;
	int basla = -1;

	while (1)
	{

		Mat frame;
		bool kont = vid.read(frame);
		flip(frame, frame, 1); //�c�nc� 1 parametresi y eksenine g�re resmin simetri�ini al�r ki videodan al�nan g�r�nt� d�zle�ir. 0 olsa x e g�re 
		if (!kont)
		{
			cout << "frame yuklenmedi" << endl;
		}
		xeks1 = (640 - (genislik * 2)) / 2;
		xeks2 = xeks1 + (genislik * 2);
		yeks1 = (480 - (yukseklik * 2)) / 2;
		yeks2 = yeks1 + (yukseklik * 2);
		arka = Mat::zeros(gec.size(), gec.type());
		line(arka, Point(xeks1, 0), Point(xeks1, 480), Scalar(0, 255, 0), 1); //arka plana belirlenen b�y�kl�kte frame olu�turulur. 
		line(arka, Point(xeks2, 0), Point(xeks2, 480), Scalar(0, 255, 0), 1);
		line(arka, Point(0, yeks1), Point(640, yeks1), Scalar(0, 255, 0), 1);
		line(arka, Point(0, yeks2), Point(640, yeks2), Scalar(0, 255, 0), 1);
		char a = waitKey(480);
		if (basla == -1) //e�er foto kayd� ba�lamad�ysa bilgilendirme yazisi i�in.
		{
			bekle = 0;
			putText(arka, "Nesneyi Ekranin Ortasina Tutunuz", Point(20, 30), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
			putText(arka, "�b� tusu ile egitime baslayiniz�", Point(20, 60), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
			putText(arka, "cikis icin esc tusuna basili tutunuz.", Point(10, 460), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
		}
		if (a == 'b') //klavyeden b ye bas�l�rsa baslay� de�i�tirir. 
			basla = basla*(-1);
		if (basla == 1 && bekle <= 10) //foto kay�ta ba�land�.
		{
			if (bekle % 2 == 0)
			{
				_snprintf_s(yazi, 250, "%d", 5 - bekle / 2); //geri say�c�
				putText(arka, yazi, Point(20, 20), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 0));
			}
			bekle++;
		}
		if (bekle >= 10)
		{
			putText(arka, "Resim Ekleniyor�", Point(20, 20), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
			_snprintf_s(yazi, 250, "D:\\train\\img\\pozitif\\poz%d.jpg", sayici); //kay�t yeri
			imwrite(yazi, frame, sparam); //belirtilen yola kaydedildi.
			_snprintf_s(yazi, 250, "D:\\train\\img\\pozitif\\poz%d.jpg", sayici); //isim 
			file << yazi << " 1 " << xeks1 << " " << yeks1 << " " << (genislik * 2) << " " << (yukseklik * 2) << endl; //belirtilen yolla beraber k�rp�lma oran� girildi. 
			sayici++;
		}
		frame = frame + arka; //webcamdan al�nan frame e yaz�lar ve �izgiler eklenerek kullan�c�ya g�sterildi. 
		imshow("Nesneyi ortaya g�sterin.", frame);
		if (waitKey(20) == 27)
		{
			file.close();
			break;
		}
	}
	return 0;
}