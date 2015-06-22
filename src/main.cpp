#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

#include "graph.h"
#include "emst_prim.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef K::Point_2 Point;

std::default_random_engine generator(clock());
std::uniform_int_distribution<int> uniform(0, 600);


double distance(const Point& i, const Point& j)
{
    return sqrt((i.hx() - j.hx()) * (i.hx() - j.hx())
                + (i.hy() - j.hy()) * (i.hy() - j.hy()));
}

int main() {
    vector<Point> points;
    const int n = 1000;
    for (int i = 0; i < n; i++) {
        int x = uniform(generator), y = uniform(generator);
        cout << x << " " << y << endl;
        points.push_back(Point(x, y));
    }

    Delaunay dt;
    dt.insert(points.begin(), points.end());

    Graph graph(n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            graph.add_edge(i, j, distance(points[i], points[j]));
            graph.add_edge(j, i, distance(points[i], points[j]));
        }
    }

    EMSTPrim prim;
    auto edges = prim.solve(graph);

    int width = 600, height = 600;
    cv::Mat picture(height, width, CV_8UC3, cv::Scalar(255, 255, 255));

    for (const auto& edge : edges) {
        cv::line(picture,
                 cv::Point(points[edge.u].hx(), points[edge.u].hy()),
                 cv::Point(points[edge.v].hx(), points[edge.v].hy()),
                 cv::Scalar(0, 0, 1));
    }

//    for (auto it = dt.finite_faces_begin(); it != dt.finite_faces_end(); ++it) {
//        auto v1 = it->vertex(0)->point();
//        auto v2 = it->vertex(1)->point();
//        auto v3 = it->vertex(2)->point();
//        cv::line(picture,
//                cv::Point(v1.hx(), v1.hy()),
//                cv::Point(v2.hx(), v2.hy()),
//                cv::Scalar(0, 0, 0));
//        cv::line(picture,
//                 cv::Point(v2.hx(), v2.hy()),
//                 cv::Point(v3.hx(), v3.hy()),
//                 cv::Scalar(0, 0, 0));
//        cv::line(picture,
//                 cv::Point(v3.hx(), v3.hy()),
//                 cv::Point(v1.hx(), v1.hy()),
//                 cv::Scalar(0, 0, 0));
//    }

    cv::namedWindow("hqy");
    cv::imshow("hqy", picture);
    cv::waitKey(0);

    return 0;
}
