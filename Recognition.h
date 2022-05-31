//
// Created by jayle on 3/20/2022.
//

#ifndef OPEN_CV_EXPERIMENTS_RECOGNITION_H
#define OPEN_CV_EXPERIMENTS_RECOGNITION_H
#include "C:\OpenCV\include\opencv2\opencv.hpp"
#include "C:\OpenCV\include\opencv2\opencv_modules.hpp"
using namespace std;
using namespace cv;
using namespace dnn::dnn4_v20201117;

namespace recog {
    class recognition {
    public:
        const string caffeConfigFile = "D:\\subDocx\\Face-detection-with-OpenCV-and-deep-learning-master\\Face-detection-with-OpenCV-and-deep-learning-master\\models\\deploy.prototxt";
        const string caffeWeightFile = "D:\\subDocx\\Face-detection-with-OpenCV-and-deep-learning-master\\Face-detection-with-OpenCV-and-deep-learning-master\\models\\res10_300x300_ssd_iter_140000.caffemodel";

        void
        detectFace(Mat img, double scale, Scalar color, double fps) {
            Net net = readNetFromCaffe(caffeConfigFile, caffeWeightFile);

            Mat inputBlob = blobFromImage(img, scale);

            net.setInput(inputBlob, "data");
            Mat detection = net.forward("detection_out");

            Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

            float confidenceThreshold = .75;

            for(int i = 0; i < detectionMat.rows; i++) {
                float  confidence = detectionMat.at<float>(i,1);

                if(confidence > confidenceThreshold) {
                    int xLeftBottom = static_cast<int>(detectionMat.at<float>(i, 3) * img.cols);
                    int yLeftBottom = static_cast<int>(detectionMat.at<float>(i, 4) * img.rows);
                    int xRightTop = static_cast<int>(detectionMat.at<float>(i, 5) * img.cols);
                    int yRightTop = static_cast<int>(detectionMat.at<float>(i, 6) * img.rows);

                    rectangle(img, Point(xLeftBottom, yLeftBottom), Point(xRightTop, yRightTop), color,2, 4);
                }
            }

            String FPS = to_string(fps);
            putText(img, FPS, Point(15,20), FONT_HERSHEY_PLAIN, scale, color, 1, LINE_AA, false);

            imshow("", img);
        };
    };
}

#endif //OPEN_CV_EXPERIMENTS_RECOGNITION_H
