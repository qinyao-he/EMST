//
// Created by hqythu on 6/20/2015.
//

#include "emst_delaunay.h"

#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <iostream>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using std::vector;
using std::pair;
using std::unordered_set;
using std::unordered_map;
using std::set;
using std::map;
using std::cout;
using std::endl;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef K::Point_2 Point_2;


vector<pair<Point, Point>> EMSTDelaunay::solve(const vector<Point>& points) const {
    size_t n = points.size();
    vector<Point_2> dt_points;

    for (const auto& point : points) {
        dt_points.push_back(Point_2(point.x, point.y));
    }

    Delaunay dt;
    dt.insert(dt_points.begin(), dt_points.end());

    Graph graph(n);
    map<Point, size_t> point_set;
    vector<Point> new_points;
    for (auto it = dt.finite_faces_begin(); it != dt.finite_faces_end(); ++it) {
        auto v1 = it->vertex(0)->point();
        auto v2 = it->vertex(1)->point();
        auto v3 = it->vertex(2)->point();
        Point p1(v1.hx(), v1.hy());
        Point p2(v2.hx(), v2.hy());
        Point p3(v3.hx(), v3.hy());
        size_t u1, u2, u3;
        if (point_set.find(p1) == point_set.end()) {
            u1 = new_points.size();
            new_points.push_back(p1);
            point_set[p1] = u1;
        } else {
            u1 = point_set[p1];
        }
        if (point_set.find(p2) == point_set.end()) {
            u2 = new_points.size();
            new_points.push_back(p2);
            point_set[p2] = u2;
        } else {
            u2 = point_set[p2];
        }
        if (point_set.find(p3) == point_set.end()) {
            u3 = new_points.size();
            new_points.push_back(p3);
            point_set[p3] = u3;
        } else {
            u3 = point_set[p3];
        }
        graph.add_edge(u1, u2, new_points[u1].distance(new_points[u2]));
        graph.add_edge(u2, u3, new_points[u2].distance(new_points[u3]));
        graph.add_edge(u3, u1, new_points[u3].distance(new_points[u1]));
    }


    auto edges = graph.mst();
    vector<pair<Point, Point>> ret;
    for (const auto& edge : edges) {
        ret.push_back(std::make_pair(new_points[edge.u], new_points[edge.v]));
    }
    return ret;
}
