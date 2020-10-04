
#include <iostream>
#include <opencv2\opencv.hpp>
#include "dirent.h\include\dirent.h"
#include<fstream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{

	string girisdosya = "D:\\train\\img\\negatif"; //negatif resimlerimizin bulunduðu klasörün yolunu string olarak tutar.
	DIR *klasor = opendir(girisdosya.c_str()); //okunmak istenen klasör açýlýr. ve klasor deðiþkenine atanýr
	struct dirent *dosyagirdisi = NULL; //Klasordeki o anki göstericideki dosyanýn hangisi olduðu sonucunu tutar. Baþlangýçta null verilmiþtir.

	ofstream file; //yazý dosyasý klasýndan bir dosya oluþturulur.
	file.open("negatif2.txt", ios::end); //pozitif.txt isimli text dosyasý açar.

	if (klasor == NULL) //eðer klasör açýlmazsa program sonlandýrýlýr.
	{
		printf("Giriþ Dosyasý acilamadi\n");
		return 1;
	}
	while ((dosyagirdisi = readdir(klasor)) != NULL)
	{
		string dosyaismi = girisdosya + "\\" + string(dosyagirdisi->d_name); //dosya yoluyla beraber dosya ismini dosyaismi deðiþkenine atar.
		Mat araresim = imread(dosyaismi.c_str());
		if (araresim.data == NULL) //resim açýlmazsa döngüye geri dön
		{
			printf("resim acilamadi\n");
			continue;
		}
		file << dosyaismi << endl;
	}
	closedir(klasor);
}