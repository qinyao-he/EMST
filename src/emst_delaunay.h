//
// Created by hqythu on 6/20/2015.
//

#ifndef EMST_EMST_DELAUNAY_H
#define EMST_EMST_DELAUNAY_H

#include <vector>

#include "emst_abstract.h"


class EMSTDelaunay : public EMSTAbstract {
private:
    typedef Graph::Edge Edge;

public:
    std::vector<std::pair<Point, Point>> solve(const std::vector<Point>& points) const;
};


#endif //EMST_EMST_DELAUNAY_H
