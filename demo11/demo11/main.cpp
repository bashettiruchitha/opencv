#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    string imageName = (argc > 1) ? argv[1] : "lena.jpg";
    Mat image = imread(imageName, IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error opening image: " << imageName << endl;
        return -1;
    }

    int ksize = 1, scale = 1, delta = 0;
    const String window_name = "Sobel Demo - Simple Edge Detector";
    namedWindow(window_name);

    Mat src, src_gray, grad;

    while (true) {
        GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
        cvtColor(src, src_gray, COLOR_BGR2GRAY);

        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y;

        Sobel(src_gray, grad_x, CV_16S, 1, 0, ksize, scale, delta, BORDER_DEFAULT);
        Sobel(src_gray, grad_y, CV_16S, 0, 1, ksize, scale, delta, BORDER_DEFAULT);

        convertScaleAbs(grad_x, abs_grad_x);
        convertScaleAbs(grad_y, abs_grad_y);

        addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
        imshow(window_name, grad);

        char key = (char)waitKey(0);
        if (key == 27) break; // Exit on ESC key
        if (key == 'k' || key == 'K') ksize = ksize < 30 ? ksize + 2 : 1;
        if (key == 's' || key == 'S') scale++;
        if (key == 'd' || key == 'D') delta++;
        if (key == 'r' || key == 'R') { ksize = 1; scale = 1; delta = 0; }
    }

    return 0;
}