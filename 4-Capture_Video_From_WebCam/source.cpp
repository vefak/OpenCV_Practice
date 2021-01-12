/*
 * Lesson 4 -- Capture Frames From Camera
 * This example shows how to open a camera and create video from 
 * consecutive frames
 * Author: Vefak Murat Akman
 *  
 */

// Import libraries
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{	
	//First check camera 
	Mat src;
	// 0 mean default camera on your computer (Laptop's webcam)
    // Internal camera: 0
    // External camera: 1
	VideoCapture vid(0); 
	
    // check if camera working
	if (!vid.isOpened()) {
		cout << "ERROR! Unable to open camera\n" << endl;
		return -1;
	}
    // Get single frame
    vid >> src;
	// Get one frame from camera to learn height&width
	if (src.empty()) {
        cerr << "ERROR! blank frame grabbed\n";
        return -1;
    }
	
	bool isColor = (src.type() == CV_8UC3); //Input image color
	VideoWriter writer; // VideoWriter object
	int cod = VideoWriter::fourcc('M','J','P','G');// Desired codec
	double fps = 30; // frame per second
	string videoname = "./video.avi"; // name of the output video file
	writer.open(videoname,cod,fps,src.size(),isColor);

	// check if we succeeded
    if (!writer.isOpened()) {
        cerr << "Could not open the output video file for write\n";
        return -1;
    }

    cout << "Writing videofile: " << videoname << endl
         << "Press any key to terminate" << endl;
    while(true)
    {
        // check if we succeeded
        if (!vid.read(src)) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // saving frames to video file
        writer.write(src);
        // show video
        imshow("Live", src);
        if (waitKey(5) >= 0)
            break;
    }
    // the videofile will be closed and released automatically in VideoWriter destructor
    return 0;
}
