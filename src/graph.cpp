//
// Created by hqythu on 6/20/2015.
//

#include "graph.h"

using std::list;


Graph::Graph(size_t n) {
    n_vertex = n;
    n_edge = 0;
    adjlist.resize(n_vertex);
}


void Graph::add_edge(int u, int v, double w) {
    Edge e(u, v, w);
    adjlist[u].push_back(e);
}


Graph::const_edge_iter Graph::edge_iter_begin(int u) const {
    return adjlist[u].begin();
}


Graph::const_edge_iter Graph::edge_iter_end(int u) const {
    return adjlist[u].end();
}

list<Graph::Edge> Graph::edge_list(int u) const {
    return adjlist[u];
}