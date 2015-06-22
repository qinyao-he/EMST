//
// Created by hqythu on 6/22/2015.
//

#include "emst_visualizer.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;


void EMSTVisualizer::show(vector<edge> edges)
{
    Mat picture(height, width, CV_8UC3, cv::Scalar(255, 255, 255));

    for (const auto& edge : edges) {
        line(picture,
             cv::Point(edge.first.x, edge.first.y),
             cv::Point(edge.second.x, edge.second.y),
             cv::Scalar(0, 0, 0));
    }

    namedWindow("hqy");
    imshow("hqy", picture);
    waitKey(0);
}