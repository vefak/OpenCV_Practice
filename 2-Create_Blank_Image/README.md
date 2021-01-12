## Lesson 2 Create Image
> Author: Vefak Murat Akman

### Code 
---
Create Image
```cpp
Mat img(480, 640, CV_8UC3, Scalar(0, 0, 0));
```
- 480x640: size of image
- CV_8UC3: 8-bit unsigned integer matrix/image with 3 channels
- Scalar(0,0,0): Color definition. Change numbers to get different colors. Since the image is encoded in 8-bit, the number of values can be given is 256. So the value for single channel must be in 0-255

```cpp
 Scalar(255, 0, 0) // Blue
 Scalar(0, 255, 0) // Green
 Scalar(0, 0, 255) // Red
 Scalar(255, 255, 255) // White
```

### Build & Run
---
To build and run code, follow commands:
```command
cmake -G "CodeLite - Unix Makefiles"
make
./blankImage
```