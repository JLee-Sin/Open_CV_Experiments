#include "Recognition.h"
#include <iostream>

using namespace recog;
using namespace cv;

int main() {
    Scalar color = Scalar (0, 0, 255);
    recognition r;
    VideoCapture capture;
    Mat frame, image;
    double FPS;
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

            Mat frameClone = frame.clone();
            r.detectFace(frameClone, scale, color, FPS);

            char c = (char) waitKey(10);
            if (c == 27) {
                break;
            }
        }
    }
    else {
        cout << "Error launching video Capture" << endl;
    }

}



