
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
ofstream file; //yazý dosyasý klasýndan bir dosya oluþturulur.
string dosyaismi; //dosya ismi string olarak tanýmlanýr. 
struct dirent *dosyagirdisi = NULL; //Klasordeki o anki göstericideki dosyanýn hangisi olduðu sonucunu tutar. Baþlangýçta null verilmiþtir. 
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
		rectangle(araresim, pt1, pt2, cvScalar(0, 255, 0, 0), 8, 8, 0); //Ýlk ve ikinci seçilen noktalarý dikdörtgen yapar
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
			rectangle(araresim, pt1, pt2, cvScalar(0, 255, 0, 0), 8, 8, 0); //Ýlk ve ikinci seçilen noktalarý dikdörtgen yapar
			imshow("Pozitif Resim Olusturucu", araresim);
			cout << "Mouse sol tiklandi, lokasyon:" << x << "x" << y << endl;
			isaretleme = false;
			char t = waitKey(0);
			if (t == 't')
			{
				file << dosyaismi<< " 1 " << xeks1 << " " << yeks1 << " " << (xeks2 - xeks1) << " " << (yeks2 - yeks1) << endl; //eðer “t” ye basýlýrsa dosyaya yazar. 
			}
		}
	}
}
int main(int argc, char* argv[])
{

	string girisdosya = "C://Users//vmakm//Desktop//labelme"; //dosya yolunu tutan string deðer

	DIR *klasor = opendir(girisdosya.c_str()); //okunmak istenen klasör açýlýr. ve klasor deðiþkenine atanýr

	file.open("C://Users//vmakm//Desktop//pozitif.txt", ios::app); //pozitif.txt isimli text dosyasý açar.
	
	namedWindow("“Pozitif Resim Olusturucu", CV_WINDOW_AUTOSIZE);

	if (klasor == NULL)
	{
		printf("Giriþ Dosyasý acilamadi\n");
		return 1;
	}
	dosyagirdisi = readdir(klasor); //klasor isimli klasörden yeni bir dosya okuyup dosyagirdisi göstericisine atar.
	while (1)
	{

		dosyaismi = girisdosya + "\\" + string(dosyagirdisi->d_name); //dosya yoluyla beraber dosya ismini dosyaismi deðiþkenine atar.
		araresim = imread(dosyaismi.c_str()); //klasördeki dosyanýn string ismi char haline çevrilerek imread fonksiyonu ile araresim Mat deðiþkenine atandý.
		

		if (araresim.data == NULL)
		{
			printf("resim acilamadi\n"); //eðer resim okunamazsa yeni bu mesajý verip yeni dosya okur. 
			dosyagirdisi = readdir(klasor);
			continue;
		}
		imshow("Pozitif Resim Olusturucu", araresim);
		setMouseCallback("Pozitif Resim Olusturucu", mausekont, NULL); //Mause fonksiyonunu çaðýrýr. 
		
		
	    char key = (char)cv::waitKey(0);
		if (key == 'y')
		{
			file << dosyaismi << " 1 " << xeks1 << " " << yeks1 << " " << (xeks2 - xeks1) << " " << (yeks2 - yeks1) << endl;
			if (dosyagirdisi == readdir(klasor) == NULL) //eðer y tuþuna basýlýrsa resmi deðiþtirir. 
			{
				break;
				return 0;
			}
		}

	}
	closedir(klasor);
}