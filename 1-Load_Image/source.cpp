
/*
 * Lesson 1 -- Load Image
 * This example shows how to open local image
 * Author: Vefak Murat Akman
 *  
 */


#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// change the file path according to your own
	Mat img = imread("./img/image.jpg"); // read image from local and assign it to Mat variable
	
	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		system("pause"); //wait until a keypress
		
		return -1;
	}

	namedWindow("MyWindow", CV_MINOR_VERSION); //create a window with the name "MyWindow"
	imshow("MyWindow", img); //display the image on the "MyWindow" window

	waitKey(0); //wait until a keypress

	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

	return 0;
}