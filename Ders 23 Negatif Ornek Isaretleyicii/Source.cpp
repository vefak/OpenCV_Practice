
#include <iostream>
#include <opencv2\opencv.hpp>
#include "dirent.h\include\dirent.h"
#include<fstream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{

	string girisdosya = "D:\\train\\img\\negatif"; //negatif resimlerimizin bulundu�u klas�r�n yolunu string olarak tutar.
	DIR *klasor = opendir(girisdosya.c_str()); //okunmak istenen klas�r a��l�r. ve klasor de�i�kenine atan�r
	struct dirent *dosyagirdisi = NULL; //Klasordeki o anki g�stericideki dosyan�n hangisi oldu�u sonucunu tutar. Ba�lang��ta null verilmi�tir.

	ofstream file; //yaz� dosyas� klas�ndan bir dosya olu�turulur.
	file.open("negatif2.txt", ios::end); //pozitif.txt isimli text dosyas� a�ar.

	if (klasor == NULL) //e�er klas�r a��lmazsa program sonland�r�l�r.
	{
		printf("Giri� Dosyas� acilamadi\n");
		return 1;
	}
	while ((dosyagirdisi = readdir(klasor)) != NULL)
	{
		string dosyaismi = girisdosya + "\\" + string(dosyagirdisi->d_name); //dosya yoluyla beraber dosya ismini dosyaismi de�i�kenine atar.
		Mat araresim = imread(dosyaismi.c_str());
		if (araresim.data == NULL) //resim a��lmazsa d�ng�ye geri d�n
		{
			printf("resim acilamadi\n");
			continue;
		}
		file << dosyaismi << endl;
	}
	closedir(klasor);
}