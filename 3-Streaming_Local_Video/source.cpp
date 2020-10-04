
/*
 * Lesson 3 -- Streaming Video
 * This example shows how to open a video from path and streaming it
 * Author: Vefak Murat Akman
 *  
 */
// Import libraries
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture vid("/home/vefak/sampleVideo.mp4"); //Create video object
	
	if (!vid.isOpened()){ //Checking the video file
		cout << "File is missing!" << endl;
	}

	double fps = vid.get(CAP_PROP_FPS); //Getting FPS value of video by using get() function
	cout << "frame per second: " << fps << endl; // Print FPS value 
	
	namedWindow("Video Streaming...", CV_MINOR_VERSION);
	
	while (1) 
	{
		Mat res; 
		bool frame_check = vid.read(res); 


		imshow("Video Streaming...", res); // Showing video
		if (waitKey(30) == 27){ // "27" means ESC in ASCII coding
			cout << "Press ESC to exit" << endl;
			break;
		}
	}
	system("Pause");
	return 0;
}