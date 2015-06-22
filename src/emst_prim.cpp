//
// Created by hqythu on 6/20/2015.
//

#include "emst_prim.h"

#include <cstddef>
#include <vector>
#include <limits>

using std::vector;
using std::pair;


vector<pair<Point, Point>> EMSTPrim::solve(const vector<Point>& points) const {
    size_t n = points.size();
    Graph graph(n);
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            graph.add_edge(i, j, points[i].distance(points[j]));
            graph.add_edge(j, i, points[i].distance(points[j]));
        }
    }
    auto edges = graph.mst();
    vector<pair<Point, Point>> ret;
    for (const auto& edge : edges) {
        ret.push_back(std::make_pair(points[edge.u], points[edge.v]));
    }
    return ret;
}
