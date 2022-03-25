#include "Recognition.h"
#include <iostream>

using namespace recog;
using namespace cv;

int main() {
    string A = R"(C:\OpenCV\etc\haarcascades\haarcascade_eye_tree_eyeglasses.xml)";
    string B = R"(C:\OpenCV\etc\haarcascades\haarcascade_frontalcatface.xml)";
    Scalar color = Scalar (0, 0, 255);
    recognition r;
    VideoCapture capture;
    Mat frame, image;

    CascadeClassifier cascade, nestedCascade;
    double scale = 1;

    nestedCascade.load(A);
    cascade.load(B);

    capture.open(0);
    if(capture.isOpened()) {
        cout << "Detection Started" << endl;
        while(true) {
            capture >> frame;

            if(frame.empty()) {
                break;
            }

            Mat frameClone = frame.clone();
            r.detectFace(frameClone, cascade, nestedCascade, scale, color);

            char c = (char) waitKey(10);
            if (c == 27) {
                break;
            }
        }
    }

}



