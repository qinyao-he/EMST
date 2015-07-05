//
// Created by hqythu on 6/20/2015.
//

#include "graph.h"

#include <limits>
#include <iostream>

using std::list;
using std::vector;


Graph::Graph(size_t n) {
    n_vertex = n;
    n_edge = 0;
    adjlist.resize(n_vertex);
}


void Graph::add_edge(int u, int v, double w) {
    Edge e(u, v, w);
    adjlist[u].push_back(e);
}


list<Graph::Edge> Graph::edge_list(int u) const {
    return adjlist[u];
}


vector<Graph::Edge> Graph::mst() const {
    size_t n = get_n_vertex();
    vector<bool> in_tree(n, false);
    vector<double> dist(n, (std::numeric_limits<double>::max)());
    vector<Edge> pre(n);
    vector<Edge> edges;
    int t = 0;
    dist[t] = 0;
    for(size_t k = 1; k < n; k++) {
        in_tree[t] = true;
        for (const auto& edge : edge_list(t)) {
            if(dist[edge.v] > edge.w && !in_tree[edge.v]) {
                dist[edge.v] = edge.w;
                pre[edge.v] = edge;
            }
        }
        double min = (std::numeric_limits<double>::max)();
        int minv = 0;
        for(size_t i = 0; i < n; i++) {
            if (min > dist[i] && !in_tree[i]) {
                min = dist[i];
                minv = i;
            }
        }
        edges.push_back(pre[minv]);
        t = minv;
    }
    return edges;
}