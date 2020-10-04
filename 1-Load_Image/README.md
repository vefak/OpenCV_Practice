## Lesson 1 Load Image
> Author: Vefak Murat Akman

### Code 
---
Read image from local and assign it to Mat variable.

```cpp
Mat img = imread("./img/image.jpg");
```

Create a window with the name "MyWindow".
```cpp
namedWindow("MyWindow", CV_MINOR_VERSION);
```

Display the image  in the "MyWindow" window:

```cpp
imshow("MyWindow", img); 
```
### Build & Run
---
TO build and run code, follow commands:
```command
cmake -G "CodeLite - Unix Makefiles"
make
./loadImage
```



<img src="./img/image.jpg"  height ="40%" width="60%">



_Press any key to close window._

