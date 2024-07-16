#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("apple.jpg");
	if (image.empty())
	{
		cout << "Image not found";
	}
	imshow("Image window", image);
	waitKey(0);
	return 0;
}