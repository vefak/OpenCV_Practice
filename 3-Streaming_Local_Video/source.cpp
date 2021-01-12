
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
	VideoCapture vid("/home/makman4/OpenCV_Practice/3-Streaming_Local_Video/SampleVideo.mp4"); //Create video object
	
	if (!vid.isOpened()){ //Checking the video file
		cout << "File is missing!" << endl;
	}

	double fps = vid.get(CAP_PROP_FPS); //Getting FPS value of video by using get() function
	cout << "frame per second: " << fps << endl; 
	
	Mat res; // Create mat object
	
	while (1) {

		// Control new frame
		bool frame_check = vid.read(res); 
		if (!frame_check){
			cout << "Could not gather new frame" << endl;
			break;
		}
		
		imshow("This Video", res); // Showing video
		
		if (waitKey(30) == 27){ // "27" means ESC in ASCII coding
			cout << "Press ESC to exit" << endl;
			break;
		}
	}
	system("Pause");
	return 0;
}