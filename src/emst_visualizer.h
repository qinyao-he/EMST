//
// Created by hqythu on 6/22/2015.
//

#ifndef EMST_EMST_VISUALIZER_H
#define EMST_EMST_VISUALIZER_H

#include <utility>
#include <vector>

#include "point.h"


class EMSTVisualizer {
public:
    EMSTVisualizer(int width, int height) : width(width), height(height) {}

    typedef std::pair<Point, Point> edge;

    void show(std::vector<edge> edges);
private:
    int width, height;
};


#endif //EMST_EMST_VISUALIZER_H
