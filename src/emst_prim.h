//
// Created by hqythu on 6/20/2015.
//

#ifndef EMST_EMST_PRIM_H
#define EMST_EMST_PRIM_H

#include <vector>

#include "emst_abstract.h


class EMSTPrim : public EMSTAbstract {
private:
    typedef Graph::Edge Edge;

public:
    std::vector<Edge> solve(const Graph& graph) const;
};


#endif //EMST_EMST_PRIM_H
