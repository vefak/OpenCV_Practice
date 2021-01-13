/*
 * Lesson 6 -- Adjust Video Brightness
 * This example shows how to increase&decrease brightness of video.
 * Author: Vefak Murat Akman
 *  
 */
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <stdio.h>
#include <iostream>
using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{	
	Mat frame;
	VideoCapture vid("/home/makman4/OpenCV_Practice/6-Adjust_Video_Brightness/video/SampleVideo.mp4");
	vid >> frame;
	int height = frame.size().height;
	int width = frame.size().width;

	if (!vid.isOpened()) {
		cout << "ERROR! Could not load video" << endl;
		return -1;
	}

	namedWindow("Orginal", CV_MINOR_VERSION);
	moveWindow("Orginal", 20,20);  // Adjust position of window on screen
	namedWindow("Darker", CV_MINOR_VERSION);
	moveWindow("Darker", width+50,20);
	namedWindow("Brighter", CV_MINOR_VERSION);
	moveWindow("Brighter",width*2+100,20);

	bool isColor = (frame.type() == CV_8UC3); //Input image color
	Size size(width, height);
	int cod = VideoWriter::fourcc('M','J','P','G');// Desired codec
	double fps = 30; // frame per second
	// Create VideoWriter object for both videos
	VideoWriter writer1("./video/bright.avi", cod, fps, size, true);
	VideoWriter writer2("./video/dark.avi", cod, fps, size, true);
	
	while (true){

		Mat frame;
		// Check frames
		bool kontrol = vid.read(frame);
		if (!kontrol){
			cout << "ERROR! Unable to get frame" << endl;
			cout << "Press any key to EXit" << endl;
			waitKey(0);
			destroyAllWindows();
			break;
		}
		// Show videos
		imshow("Orginal", frame);
		Mat frame1 = frame + Scalar(75, 75, 75);
		imshow("Brighter", frame1);
		writer1.write(frame1);
		Mat frame2 = frame - Scalar(75, 75, 75);
		imshow("Darker", frame2);
		writer2.write(frame2);
		
		// Press any key to exit
		if (waitKey(5) >= 0)
           	break;

	}
	// Close all windows 
	destroyAllWindows();
	return 0;
}
