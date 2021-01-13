/*
 * Lesson 98-- Histogram Equalization with RGB image
 * Histogram is a graphical representation of the intensity distribution of an image.
 * It quantifies the number of pixels for each intensity value considered.
 * Histogram Equalization  is a method that improves the contrast in an image, in order to stretch out the intensity range.
 * 
 * Author: Vefak Murat Akman
 *  
 */

// Import libraries
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include <stdio.h>
#include <iostream>

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
	vector<uchar> durum; //nokta var m� yok mu
	vector<float> hata; //hesaplama hatas�
	enokta.push_back(Point(320, 240)); //ilk noktan�n yeri
	vid >> frame;
	cvtColor(frame, yeni, CV_BGR2GRAY);

	while (true)
	{
		eski = yeni.clone(); //hata vermesin diye clone kullan�ld�. 
		vid >> frame;
		cvtColor(frame, yeni, CV_BGR2GRAY);
		calcOpticalFlowPyrLK(eski, yeni, enokta, ynokta, durum, hata); //eski resimdeki noktay� yeni resimde arar
		line(frame, ynokta[0], ynokta[0], Scalar(255, 255, 255), 3, 8, 0);
		imshow("deneme", frame);
		enokta[0] = ynokta[0]; //yeni bulunan noktay� eski yapar.

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

