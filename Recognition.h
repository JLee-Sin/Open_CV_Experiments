//
// Created by jayle on 3/20/2022.
//

#ifndef OPEN_CV_EXPERIMENTS_RECOGNITION_H
#define OPEN_CV_EXPERIMENTS_RECOGNITION_H
#include "C:\OpenCV\include\opencv2\opencv.hpp"
#include "C:\OpenCV\include\opencv2\opencv_modules.hpp"
using namespace std;
using namespace cv;

namespace recog {
    class recognition {
    public:

        void
        detectFace(Mat &img, CascadeClassifier &cascade, CascadeClassifier &nestedCascade, double scale, Scalar color) {
            vector<Rect> faces, faces2;
            Mat gray, smallImage;

            cvtColor(img, gray, COLOR_BGR2GRAY);
            double fx = 1 / scale;

            resize(gray, smallImage, Size(), fx, fx, INTER_LINEAR_EXACT);
            equalizeHist(smallImage, smallImage);

            cascade.detectMultiScale(smallImage, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

            for (size_t x = 0; x < faces.size(); x++) {
                Rect r = faces[x];
                Mat smallImgROI;
                vector<Rect> nestedObjects;
                Point center;
                Scalar color = Scalar(255, 0, 0); // Color for Drawing tool
                int radius;

                double aspect_ratio = (double) r.width / r.height;
                if (0.75 < aspect_ratio && aspect_ratio < 1.3) {
                    rectangle(img, Point(cvRound(r.x * scale), cvRound(r.y * scale)),
                              Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)), color,
                              3, 8, 0);
                }
            }
        };
    };
}

#endif //OPEN_CV_EXPERIMENTS_RECOGNITION_H
