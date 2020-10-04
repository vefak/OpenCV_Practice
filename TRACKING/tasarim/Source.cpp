#include <opencv2\opencv.hpp>
#include <iostream>
#include <opencv2\imgproc.hpp>


using namespace std; 
using namespace cv;

int main(int argc, char* argv[])
{  
	int a, b; //parmaðýn koordinatlarý için kullanýlacak global deðiþkenler
	
	bool flag = true;


	CascadeClassifier nesne; // snýflandýrýcý 
	nesne.load("final4.xml"); // sýnýflandýrýcý nesneye tanýmlandý

	

	VideoCapture vid(0); // webcam açýldý
	
	if (!vid.isOpened()) //kameranýn çalýþma durumunu kontrol etmek için
	{
		cout << "webcam yuklenemedi" << endl;
		system("Pause");
		return -1;
	}

	    
	Mat frame2, thresholdImage, gray, blurPic; // yapacaðýmýz morfolojik iþlemler için boþ matrisler 
	
	//pencereler belirtilen isimlerde oluþturuldu
	namedWindow("algilanan", 1);
	namedWindow("gray", 1);
	namedWindow("thresholdImage", 1);
	namedWindow("blurPic", 1);

	namedWindow("tracking", 1);
	namedWindow("cizim", 1);

	
	while (flag) // parmak algýlama ve konum tespiti
	{ 
	

		vid >> frame2;  // kameradan yeni frame alma
		cvtColor(frame2, gray, CV_BGR2GRAY); //görüntüyü siyah beyaz yapma
		equalizeHist(gray, thresholdImage); //histogram eþitleme
		blur(thresholdImage, blurPic, Size(15,15)); // gürültüden kurtulma
		
		vector<Rect> objVec; // rectangle türünde vektör oluþturuldu
		

		nesne.detectMultiScale(blurPic, objVec, 1.1, 3, 0, Size(30, 30));
		/*
		detectMultiScale(const Mat& image, vector<Rect>& objects, double scaleFactor=1.1,
		...int minNeighbors=3,  Size minSize=Size(), Size maxSize=Size())
		@const Mat& image: Input image
		@vector<Rect>& objects: deðerlerin saklanacaðý vektör
		@double scaleFactor=1.1: eðitimde tanýnmýþ sabit boyutun ne kadar ölçekleneceði
		@minNeighbors=3: Her bir aday dikdörtgenin kaç tane komþu bulunduracaðýný belirten parametre.
		@Size: detect edilecek nesnenin max ve min boyutlarý
		*/

		for (int i = 0; i < objVec.size(); i++)
		{
			// noktalar bulunur. Kare çizilir. "Parmak" yazýlýr
			Point pt1(objVec[i].x + objVec[i].width, objVec[i].y + objVec[i].height);
			Point pt2(objVec[i].x, objVec[i].y);
			rectangle(frame2, pt1, pt2, Scalar(0, 255, 0), 1, 8, 0);
			putText(frame2, "Parmak", pt2, CV_FONT_HERSHEY_TRIPLEX, 0.8, Scalar(0,255,55), 1, 8, false);
			// parmaðýn orta noktasý bulunur ve global deðiþkenlere atanýr
	        a = objVec[i].x + (objVec[i].width/2);
			b = objVec[i].y +(objVec[i].height/2);
			
	
		}
		// frameler gösterilir
        imshow("thresholdImage", thresholdImage);
		imshow("gray", gray);
		imshow("algilanan", frame2);
		imshow("blurPic", blurPic);
		waitKey(33);

		/*Eðer "d" tuþuna basýlý tutulursa döngü kapanýr ve trackinge geçilir.
		Koordinatlar belirlenir*/
		if (waitKey(30) == 100) // 'd' 
		{
			flag = false;
			
		}	
		
}
	
	if (!flag) {
	
	//morfolojik iþlemler ve çizim için matriksler oluþturulur
		Mat yeni, eski, frame;
		Mat cizim = Mat::zeros(frame2.size(), CV_8UC3); // matriksin boyutu videonun boyutu kadar.
		// opticalFlow fonksiyonunu kullanmak için çeþitli vektörler oluþturulur
		vector<Point2f> enokta, ynokta; 
		vector<uchar> durum; 
		vector<float> hata;
		enokta.push_back(Point (a,b));  // a ve b noktalarý enokta dizisine yazýlýr
		vid >> frame; // videodan yeni frame okuma
		cvtColor(frame, yeni, CV_BGR2GRAY); 

		while (true) //tracking yapan döngü
		{
			eski = yeni.clone(); // memory hatasý alýnmasýn diye frame yeni frame kopyalanýr
			vid >> frame;   // videodan yeni frame okuma
			cvtColor(frame, yeni, CV_BGR2GRAY);
			calcOpticalFlowPyrLK(eski, yeni, enokta, ynokta, durum, hata, Size(21,21), 3); 
			
			
			/*Calculates an optical flow for a sparse feature set using the iterative Lucas-Kanade method with pyramids.
			 void calcOpticalFlowPyrLK(InputArray prevImg, InputArray nextImg, InputArray prevPts, InputOutputArray nextPts, 
...status, OutputArray err, Size winSize=Size(21,21), int maxLevel=3, )
			
			@InputArray prevImg: input image
			@InputArray nextImg: output image
			@InputArray prevPts: geçmiþ noktalar
			@InputOutputArray nextPts: yeni noktalar
			@status: Karþýlýk gelen featurelar bulunursa 1 aksi durumda 0 veren vektör
			@err: hatalarýn çýkýþ vektörü. her giriþ noktasý için eþlenen hatayý verir
			@winSize: her piramid seviyesinde aranacak alanýn boyutu
			*/

			// takip edilecek piksel iþretlenir ve geçtiði noktalar çizilir.
			line(frame, ynokta[0], ynokta[0], Scalar(4, 22, 123), 8, 8, 0);
			line(cizim, enokta[0], ynokta[0], Scalar(64, 120, 0), 4, 2, 0);
			imshow("tracking", frame+cizim);
			imshow("cizim", cizim);
			enokta[0] = ynokta[0];  // yeni noktalar eski noktalar olur

		
			if (waitKey(30) == 27) // ESC basýlý tutulunca çýkýlýr
			{
				break;
			}
		}

		return 0;
	}
}
