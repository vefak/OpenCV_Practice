
#include <iostream>
#include <opencv2\opencv.hpp>
#include "dirent.h\include\dirent.h"
#include<fstream>
#include <string>
#include "conio.h"

using namespace std;
using namespace cv;

Mat araresim;
bool isaretleme = false;
ofstream file; //yaz� dosyas� klas�ndan bir dosya olu�turulur.
string dosyaismi; //dosya ismi string olarak tan�mlan�r. 
struct dirent *dosyagirdisi = NULL; //Klasordeki o anki g�stericideki dosyan�n hangisi oldu�u sonucunu tutar. Ba�lang��ta null verilmi�tir. 
int xeks1, xeks2;
int yeks1, yeks2;

void mausekont(int event, int x, int y, int flags, void *kullanici)
{
	araresim = imread(dosyaismi.c_str());
	if (event == EVENT_LBUTTONDOWN)
	{
		isaretleme = true;
		xeks1 = x;
		yeks1 = y;
		cout << "Mouse sol tiklandi, lokasyon:" << x << "x" << y << endl;
	}
	if (event == EVENT_MOUSEMOVE&&isaretleme)
	{
		xeks2 = x;
		yeks2 = y;
		Point pt1(xeks1, yeks1);
		Point pt2(xeks2, yeks2);
		rectangle(araresim, pt1, pt2, cvScalar(0, 255, 0, 0), 8, 8, 0); //�lk ve ikinci se�ilen noktalar� dikd�rtgen yapar
		imshow("Pozitif Resim Olusturucu", araresim);
	}
	if (event == EVENT_LBUTTONUP)
	{
		if (isaretleme)
		{
			xeks2 = x;
			yeks2 = y;
			Point pt1(xeks1, yeks1);
			Point pt2(xeks2, yeks2);
			rectangle(araresim, pt1, pt2, cvScalar(0, 255, 0, 0), 8, 8, 0); //�lk ve ikinci se�ilen noktalar� dikd�rtgen yapar
			imshow("Pozitif Resim Olusturucu", araresim);
			cout << "Mouse sol tiklandi, lokasyon:" << x << "x" << y << endl;
			isaretleme = false;
			char t = waitKey(0);
			if (t == 't')
			{
				file << dosyaismi<< " 1 " << xeks1 << " " << yeks1 << " " << (xeks2 - xeks1) << " " << (yeks2 - yeks1) << endl; //e�er �t� ye bas�l�rsa dosyaya yazar. 
			}
		}
	}
}
int main(int argc, char* argv[])
{

	string girisdosya = "C://Users//vmakm//Desktop//labelme"; //dosya yolunu tutan string de�er

	DIR *klasor = opendir(girisdosya.c_str()); //okunmak istenen klas�r a��l�r. ve klasor de�i�kenine atan�r

	file.open("C://Users//vmakm//Desktop//pozitif.txt", ios::app); //pozitif.txt isimli text dosyas� a�ar.
	
	namedWindow("�Pozitif Resim Olusturucu", CV_WINDOW_AUTOSIZE);

	if (klasor == NULL)
	{
		printf("Giri� Dosyas� acilamadi\n");
		return 1;
	}
	dosyagirdisi = readdir(klasor); //klasor isimli klas�rden yeni bir dosya okuyup dosyagirdisi g�stericisine atar.
	while (1)
	{

		dosyaismi = girisdosya + "\\" + string(dosyagirdisi->d_name); //dosya yoluyla beraber dosya ismini dosyaismi de�i�kenine atar.
		araresim = imread(dosyaismi.c_str()); //klas�rdeki dosyan�n string ismi char haline �evrilerek imread fonksiyonu ile araresim Mat de�i�kenine atand�.
		

		if (araresim.data == NULL)
		{
			printf("resim acilamadi\n"); //e�er resim okunamazsa yeni bu mesaj� verip yeni dosya okur. 
			dosyagirdisi = readdir(klasor);
			continue;
		}
		imshow("Pozitif Resim Olusturucu", araresim);
		setMouseCallback("Pozitif Resim Olusturucu", mausekont, NULL); //Mause fonksiyonunu �a��r�r. 
		
		
	    char key = (char)cv::waitKey(0);
		if (key == 'y')
		{
			file << dosyaismi << " 1 " << xeks1 << " " << yeks1 << " " << (xeks2 - xeks1) << " " << (yeks2 - yeks1) << endl;
			if (dosyagirdisi == readdir(klasor) == NULL) //e�er y tu�una bas�l�rsa resmi de�i�tirir. 
			{
				break;
				return 0;
			}
		}

	}
	closedir(klasor);
}