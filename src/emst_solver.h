//
// Created by hqythu on 6/22/2015.
//

#ifndef EMST_EMST_SOLVER_H
#define EMST_EMST_SOLVER_H

#include <vector>
#include <memory>
#include <utility>

#include "emst_abstract.h"
#include "point.h"


class EMSTSolver {
public:
    EMSTSolver(std::shared_ptr<EMSTAbstract> emst);

    typedef std::pair<Point, Point> edge;

    std::vector<edge> solve(const std::vector<Point>& points);

private:
    std::shared_ptr<EMSTAbstract> emst;
};


#endif //EMST_EMST_SOLVER_H
