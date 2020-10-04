#include <opencv2\opencv.hpp>
#include <iostream>
#include <opencv2\imgproc.hpp>


using namespace std; 
using namespace cv;

int main(int argc, char* argv[])
{  
	int a, b; //parma��n koordinatlar� i�in kullan�lacak global de�i�kenler
	
	bool flag = true;


	CascadeClassifier nesne; // sn�fland�r�c� 
	nesne.load("final4.xml"); // s�n�fland�r�c� nesneye tan�mland�

	

	VideoCapture vid(0); // webcam a��ld�
	
	if (!vid.isOpened()) //kameran�n �al��ma durumunu kontrol etmek i�in
	{
		cout << "webcam yuklenemedi" << endl;
		system("Pause");
		return -1;
	}

	    
	Mat frame2, thresholdImage, gray, blurPic; // yapaca��m�z morfolojik i�lemler i�in bo� matrisler 
	
	//pencereler belirtilen isimlerde olu�turuldu
	namedWindow("algilanan", 1);
	namedWindow("gray", 1);
	namedWindow("thresholdImage", 1);
	namedWindow("blurPic", 1);

	namedWindow("tracking", 1);
	namedWindow("cizim", 1);

	
	while (flag) // parmak alg�lama ve konum tespiti
	{ 
	

		vid >> frame2;  // kameradan yeni frame alma
		cvtColor(frame2, gray, CV_BGR2GRAY); //g�r�nt�y� siyah beyaz yapma
		equalizeHist(gray, thresholdImage); //histogram e�itleme
		blur(thresholdImage, blurPic, Size(15,15)); // g�r�lt�den kurtulma
		
		vector<Rect> objVec; // rectangle t�r�nde vekt�r olu�turuldu
		

		nesne.detectMultiScale(blurPic, objVec, 1.1, 3, 0, Size(30, 30));
		/*
		detectMultiScale(const Mat& image, vector<Rect>& objects, double scaleFactor=1.1,
		...int minNeighbors=3,  Size minSize=Size(), Size maxSize=Size())
		@const Mat& image: Input image
		@vector<Rect>& objects: de�erlerin saklanaca�� vekt�r
		@double scaleFactor=1.1: e�itimde tan�nm�� sabit boyutun ne kadar �l�eklenece�i
		@minNeighbors=3: Her bir aday dikd�rtgenin ka� tane kom�u bulunduraca��n� belirten parametre.
		@Size: detect edilecek nesnenin max ve min boyutlar�
		*/

		for (int i = 0; i < objVec.size(); i++)
		{
			// noktalar bulunur. Kare �izilir. "Parmak" yaz�l�r
			Point pt1(objVec[i].x + objVec[i].width, objVec[i].y + objVec[i].height);
			Point pt2(objVec[i].x, objVec[i].y);
			rectangle(frame2, pt1, pt2, Scalar(0, 255, 0), 1, 8, 0);
			putText(frame2, "Parmak", pt2, CV_FONT_HERSHEY_TRIPLEX, 0.8, Scalar(0,255,55), 1, 8, false);
			// parma��n orta noktas� bulunur ve global de�i�kenlere atan�r
	        a = objVec[i].x + (objVec[i].width/2);
			b = objVec[i].y +(objVec[i].height/2);
			
	
		}
		// frameler g�sterilir
        imshow("thresholdImage", thresholdImage);
		imshow("gray", gray);
		imshow("algilanan", frame2);
		imshow("blurPic", blurPic);
		waitKey(33);

		/*E�er "d" tu�una bas�l� tutulursa d�ng� kapan�r ve trackinge ge�ilir.
		Koordinatlar belirlenir*/
		if (waitKey(30) == 100) // 'd' 
		{
			flag = false;
			
		}	
		
}
	
	if (!flag) {
	
	//morfolojik i�lemler ve �izim i�in matriksler olu�turulur
		Mat yeni, eski, frame;
		Mat cizim = Mat::zeros(frame2.size(), CV_8UC3); // matriksin boyutu videonun boyutu kadar.
		// opticalFlow fonksiyonunu kullanmak i�in �e�itli vekt�rler olu�turulur
		vector<Point2f> enokta, ynokta; 
		vector<uchar> durum; 
		vector<float> hata;
		enokta.push_back(Point (a,b));  // a ve b noktalar� enokta dizisine yaz�l�r
		vid >> frame; // videodan yeni frame okuma
		cvtColor(frame, yeni, CV_BGR2GRAY); 

		while (true) //tracking yapan d�ng�
		{
			eski = yeni.clone(); // memory hatas� al�nmas�n diye frame yeni frame kopyalan�r
			vid >> frame;   // videodan yeni frame okuma
			cvtColor(frame, yeni, CV_BGR2GRAY);
			calcOpticalFlowPyrLK(eski, yeni, enokta, ynokta, durum, hata, Size(21,21), 3); 
			
			
			/*Calculates an optical flow for a sparse feature set using the iterative Lucas-Kanade method with pyramids.
			 void calcOpticalFlowPyrLK(InputArray prevImg, InputArray nextImg, InputArray prevPts, InputOutputArray nextPts, 
...status, OutputArray err, Size winSize=Size(21,21), int maxLevel=3, )
			
			@InputArray prevImg: input image
			@InputArray nextImg: output image
			@InputArray prevPts: ge�mi� noktalar
			@InputOutputArray nextPts: yeni noktalar
			@status: Kar��l�k gelen featurelar bulunursa 1 aksi durumda 0 veren vekt�r
			@err: hatalar�n ��k�� vekt�r�. her giri� noktas� i�in e�lenen hatay� verir
			@winSize: her piramid seviyesinde aranacak alan�n boyutu
			*/

			// takip edilecek piksel i�retlenir ve ge�ti�i noktalar �izilir.
			line(frame, ynokta[0], ynokta[0], Scalar(4, 22, 123), 8, 8, 0);
			line(cizim, enokta[0], ynokta[0], Scalar(64, 120, 0), 4, 2, 0);
			imshow("tracking", frame+cizim);
			imshow("cizim", cizim);
			enokta[0] = ynokta[0];  // yeni noktalar eski noktalar olur

		
			if (waitKey(30) == 27) // ESC bas�l� tutulunca ��k�l�r
			{
				break;
			}
		}

		return 0;
	}
}
