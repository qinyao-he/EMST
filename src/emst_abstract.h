//
// Created by hqythu on 6/20/2015.
//

#ifndef EMST_EMST_ABSTRACT_H
#define EMST_EMST_ABSTRACT_H

#include <vector>

#include "graph.h"


class EMSTAbstract {
private:
    typedef Graph::Edge Edge;

public:
    virtual std::vector<Edge> solve(const Graph& graph) const = 0;
};


#endif //EMST_EMST_ABSTRACT_H
