## Lesson 3 Streaming Local Video
> Author: Vefak Murat Akman

### Code 
---
Class for video capturing from video files, image sequences or cameras. Create a VideoCapture object named as vid and passing local path. [1]

```cpp
VideoCapture vid("$YOUR_PATH$/sampleVideo.mp4"); 
```
The class Mat represents an n-dimensional dense numerical single-channel or multi-channel array. It can be used to store real or complex-valued vectors and matrices, grayscale or color images, voxel volumes, vector fields, point clouds, tensors, histograms [2]

```cpp
Mat res;
```
Display the image  in the "This Video" window. Videos are sequence of consecutive frames. Basically, These frames can be shown consecutively using a while loop

```cpp
while(1) {
...

imshow("This Video", res); 

...
    }
```
Mostly, developers wants to control input data asset. We can control this asset through read() method of VideoCapture class. If no new frames are gathered, the loop will be end.

```cpp
bool frame_check = vid.read(res); 
if (!frame_check){
	cout << "Could not gather new frame" << endl;
    break;
}    
```

### Build & Run
---
To build and run code, follow commands:
```command
cmake -G "CodeLite - Unix Makefiles"
make
./streamVideo
```

### References
[1] [VideoCapture Class Reference](https://docs.opencv.org/3.4/d8/dfe/classcv_1_1VideoCapture.html)

[2] [Mat Class](https://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html#details)
