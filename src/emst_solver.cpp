//
// Created by hqythu on 6/22/2015.
//

#include "emst_solver.h"

using std::shared_ptr;
using std::vector;


EMSTSolver::EMSTSolver(shared_ptr<EMSTAbstract> emst)
        : emst(emst) {

}


vector<EMSTSolver::edge> EMSTSolver::solve(const std::vector<Point> &points) {
    return emst->solve(points);
}