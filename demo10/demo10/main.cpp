#include <iostream> 
#include <opencv2/core/core.hpp> 

// Library include for drawing shapes 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
using namespace cv;
using namespace std;

// Function to demonstrate the 
// opening morphological operator 
int openingMorphological()
{
    // Reading the Image 
    Mat image = imread(
        "LinuxLogo.jpg",
        IMREAD_GRAYSCALE);

    // Check if the image is 
    // created successfully or not 
    if (!image.data) {
        cout << "Could not open or"
            << " find the image\n";

        return 0;
    }

    // Create a structuring element 
    int morph_size = 2;
    Mat element = getStructuringElement(
        MORPH_RECT,
        Size(2 * morph_size + 1,
            2 * morph_size + 1),
        Point(morph_size,
            morph_size));
    Mat output;

    // Opening 
    morphologyEx(image, output,
        MORPH_OPEN, element,
        Point(-1, -1), 2);

    // Display the image 
    imshow("source", image);
    imshow("Opening", output);
    waitKey();

    return 0;
}

// Driver Code 
int main()
{

    openingMorphological();

    return 0;
}