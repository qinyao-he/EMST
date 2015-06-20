#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

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

int main() {
    vector<Point> points;
    for (int i = 0; i < 10; i++) {
        int x = uniform(generator), y = uniform(generator);
        cout << x << " " << y << endl;
        points.push_back(Point(x, y));
    }

    Delaunay dt;
    dt.insert(points.begin(), points.end());

    int width = 600, height = 600;
    cv::Mat picture(height, width, CV_8UC3, cv::Scalar(255, 255, 255));

    for (auto it = dt.finite_faces_begin(); it != dt.finite_faces_end(); ++it) {
        auto v1 = it->vertex(0)->point();
        auto v2 = it->vertex(1)->point();
        auto v3 = it->vertex(2)->point();
        cv::line(picture,
                cv::Point(v1.hx(), v1.hy()),
                cv::Point(v2.hx(), v2.hy()),
                cv::Scalar(0, 0, 0));
        cv::line(picture,
                 cv::Point(v2.hx(), v2.hy()),
                 cv::Point(v3.hx(), v3.hy()),
                 cv::Scalar(0, 0, 0));
        cv::line(picture,
                 cv::Point(v3.hx(), v3.hy()),
                 cv::Point(v1.hx(), v1.hy()),
                 cv::Scalar(0, 0, 0));
    }

    cv::namedWindow("hqy");
    cv::imshow("hqy", picture);
    cv::waitKey(0);

    return 0;
}
