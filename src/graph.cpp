//
// Created by hqythu on 6/20/2015.
//

#include "graph.h"


Graph::Graph(int n = 0) {
    n_vertex = n;
    n_edge = 0;
    adjlist.resize(n_vertex);
}


void Graph::add_edge(int u, int v, double w) {
    Edge e(u, v, w);
    adjlist[u].push_back(e);
}


Graph::edge_iter Graph::edge_iter_begin(int u) const {
    return adjlist[u].begin();
}


Graph::edge_iter Graph::edge_iter_end(int u) const {
    return adjlist[u].end();
}


const Graph::edge_list& Graph::edge_list(int u) const {
    return adjlist[u];
}
