//
// Created by hqythu on 6/20/2015.
//

#ifndef EMST_GRAPH_H
#define EMST_GRAPH_H

#include <vector>
#include <list>


class Graph {
public:
    struct Edge {
        int u, v;
        double w;
    };

    Graph(int n = 0);

    void add_edge(int u, int v, double w);

    typedef std::list<Edge>::iterator edge_iter;
    typedef std::list<Edge> edge_list;
    edge_iter edge_iter_begin(int u) const;
    edge_iter edge_iter_end(int u) const;
    const edge_list& edge_list(int u) const;


private:
    int n_vertex;
    int n_edge;
    std::vector<std::list<Edge>> adjlist;
};


#endif //EMST_GRAPH_H
