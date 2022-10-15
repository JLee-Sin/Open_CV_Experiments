#include "Recognition.h"
#include <iostream>

void task1(Mat mat, double scale, Scalar scalar, float fps);

using namespace recog;
using namespace cv;
Mat finImg;

int main() {
    Scalar color = Scalar (0, 0, 255);
    VideoCapture capture;
    Mat frame, image;
    float FPS;
    double scale = 1;

    capture.open(0);
    if(capture.isOpened()) {
        cout << "Detection Started" << endl;
        while(true) {
            capture >> frame;
            FPS = capture.get(CAP_PROP_FPS);

            if(frame.empty()) {
                break;
            }

            thread t1(task1,frame, scale, color, FPS);


            char c = (char) waitKey(10);
            if (c == 27) {
                break;
            }
            t1.join();
            imshow("", finImg);
        }
    }
    else {
        cout << "Error launching video Capture" << endl;
    }

}

void task1(Mat frame, double scale, Scalar color, float FPS) {
    recognition r;
    finImg= r.detectFace(frame, scale, color, FPS);
}



