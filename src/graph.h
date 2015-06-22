//
// Created by hqythu on 6/20/2015.
//

#ifndef EMST_GRAPH_H
#define EMST_GRAPH_H

#include <cstddef>
#include <vector>
#include <list>


class Graph {
public:
    struct Edge {
        Edge(int u = 0, int v = 0, double w = 0) : u(u), v(v), w(w) {}
        int u, v;
        double w;
    };

    Graph(size_t n = 0);

    void add_edge(int u, int v, double w);

    std::list<Edge> edge_list(int u) const;

    size_t get_n_vertex() const { return n_vertex; }

    std::vector<Edge> mst() const;

private:
    size_t n_vertex;
    size_t n_edge;
    std::vector<std::list<Edge>> adjlist;
};


#endif //EMST_GRAPH_H
