#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <memory>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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

std::default_random_engine generator(clock());
std::uniform_int_distribution<int> uniform(0, 600);


int main() {
    vector<Point> points;
    const int n = 5000;
    for (int i = 0; i < n; i++) {
        int x = uniform(generator), y = uniform(generator);
        //cout << x << " " << y << endl;
        points.push_back(Point(x, y));
    }

    auto algo = std::make_shared<EMSTDelaunay>();
    EMSTSolver solver(algo);
    auto result = solver.solve(points);
    EMSTVisualizer visualizer(600, 600);
    visualizer.show(result);

    return 0;
}
