#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int getMaxBrightness(const Mat& image) {
    int maxVal = 0;

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            int pixel = image.at<uchar>(i, j);
            if (pixel > maxVal) {
                maxVal = pixel;
            }
        }
    }

    return maxVal;
}

int main() {
    Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);
    
    int maxBrightness = getMaxBrightness(img);
    cout << "" << maxBrightness << endl;

    return 0;
}
