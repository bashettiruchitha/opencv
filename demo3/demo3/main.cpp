#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the image in grayscale mode
    cv::Mat img = cv::imread("aloeL.jpg", cv::IMREAD_GRAYSCALE);

    // Check if the image is loaded successfully
    if (img.empty()) {
        std::cerr << "Error: Could not load image." << std::endl;
        return -1;
    }

    // Resize the image to 400x400
    cv::resize(img, img, cv::Size(400, 400));

    // Define the kernel for the homogeneous filter
    cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F) / 9;

    // Apply the homogeneous filter
    cv::Mat h_filter;
    cv::filter2D(img, h_filter, -1, kernel);

    // Apply the average (blur) filter
    cv::Mat blur;
    cv::blur(img, blur, cv::Size(2, 2));

    // Apply the Gaussian filter
    cv::Mat gau;
    cv::GaussianBlur(img, gau, cv::Size(5, 5), 0);

    // Apply the median filter
    cv::Mat med;
    cv::medianBlur(img, med, 5);

    // Apply the bilateral filter
    cv::Mat bi_f;
    cv::bilateralFilter(img, bi_f, 9, 75, 75);

    // Display the original and filtered images
    cv::imshow("Original", img);
    cv::imshow("Homogeneous Filter", h_filter);
    cv::imshow("Blur Filter", blur);
    cv::imshow("Gaussian Filter", gau);
    cv::imshow("Median Filter", med);
    cv::imshow("Bilateral Filter", bi_f);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    // Destroy all windows
    cv::destroyAllWindows();

    return 0;
}