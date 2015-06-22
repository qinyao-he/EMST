//
// Created by hqythu on 6/20/2015.
//

#ifndef EMST_EMST_ABSTRACT_H
#define EMST_EMST_ABSTRACT_H

#include <vector>
#include <utility>

#include "graph.h"
#include "point.h"


class EMSTAbstract {
private:
    typedef Graph::Edge Edge;

public:
    virtual std::vector<std::pair<Point, Point>> solve(const std::vector<Point>& points) const = 0;
};


#endif //EMST_EMST_ABSTRACT_H
