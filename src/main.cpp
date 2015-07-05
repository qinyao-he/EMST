#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <memory>
#include <string>

#include <opencv2/core/core.hpp>

#include "point.h"
#include "emst_abstract.h"
#include "emst_prim.h"
#include "emst_delaunay.h"
#include "emst_solver.h"
#include "emst_visualizer.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;


int main(int argc, char** argv) {
    vector<Point> points;
    int n = 500;
    int range = 800;
    std::mt19937 generator(clock());
    std::uniform_int_distribution<int> uniform(0, range);
    if (argc == 1) {
        for (int i = 0; i < n; i++) {
            int x = uniform(generator), y = uniform(generator);
            points.push_back(Point(x, y));
        }
    } else {
        string filename(argv[1]);
        ifstream inf(filename);
        inf >> n;
        for (int i = 0; i < n; i++) {
            int x, y;
            inf >> x >> y;
            if (x > range) range = x;
            if (y > range) range = y;
            points.push_back(Point(x, y));
        }
    }
    auto algo = std::make_shared<EMSTDelaunay>();
    EMSTSolver solver(algo);
    auto result = solver.solve(points);
    EMSTVisualizer visualizer(range, range);
    visualizer.show(result);

    return 0;
}
