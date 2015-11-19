#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat src, dst;
    char src_filename[] = "../images/src.png",
         dst_filename[] = "../images/dst.png";

    src = imread(src_filename, CV_LOAD_IMAGE_COLOR);
    dst = imread(dst_filename, CV_LOAD_IMAGE_COLOR);

    if (!src.data) {
        printf("Could not open the image file '%s'", src_filename);
        return -1;
    }

    if (!dst.data) {
        printf("Could not open the image file '%s'", dst_filename);
        return -1;
    }

    Mat tmp(cvSize(src.cols + dst.cols, src.rows), CV_8UC3, Scalar(255, 255, 255));
    src.copyTo(tmp(Rect(0, 0, src.cols, tmp.rows)));
    dst.copyTo(tmp(Rect(src.cols, 0, dst.cols, dst.rows)));

    imwrite("../images/src.png", tmp);

    return 0;
}