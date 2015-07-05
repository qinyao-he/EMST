#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "../src/point.h"
#include "../src/emst_delaunay.h"
#include "../src/emst_prim.h"
#include "../src/emst_solver.h"


using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;


inline void wrong_handle()
{
    cout << "Bad command." << endl;
    cout << "Run with out parameter to test, or 'generate number filename' to generate testcase." << endl;
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        const int TEST_NUM = 5;
        for (int i = 0; i < TEST_NUM; i++) {
            vector<Point> points;
            string filename = "../testcase/input" + std::to_string(i + 1) + ".txt";
            cout << filename << endl;
            ifstream inf(filename);
            int n;
            inf >> n;
            for (int i = 0; i < n; i++) {
                int x, y;
                inf >> x >> y;
                points.push_back(Point(x, y));
            }
            auto algo1 = std::make_shared<EMSTDelaunay>();
            EMSTSolver solver1(algo1);
            auto result1 = solver1.solve(points);
            auto algo2 = std::make_shared<EMSTPrim>();
            EMSTSolver solver2(algo2);
            auto result2 = solver2.solve(points);

            auto cmp = [](const EMSTSolver::edge& e1, const EMSTSolver::edge& e2) {
              if (e1.first < e2.first) {
                  return true;
              } else if(e2.first < e1.first) {
                  return false;
              } else {
                  if(e1.second < e2.second) {
                      return true;
                  } else {
                      return false;
                  }
              }
            };

            decltype(result1) r1;
            decltype(result2) r2;

            for (const auto& e : result1) {
                r1.push_back(e);
                r1.push_back(std::make_pair(e.second, e.first));
            }
            for (const auto& e : result2) {
                r2.push_back(e);
                r2.push_back(std::make_pair(e.second, e.first));
            }

            std::sort(r1.begin(), r1.end(), cmp);
            std::sort(r2.begin(), r2.end(), cmp);

            if (r1 == r2) {
                cout << "testcase " + std::to_string(i + 1) << " success" << endl;
            } else {
                cout << "testcase " + std::to_string(i + 1) << " failed" << endl;
            }

            inf.close();
        }
    } else {
        if(string(argv[1]) == "generate") {
            int n;
            string filename;
            try {
                n = atoi(argv[2]);
                filename = string(argv[3]);
            } catch (...) {
                wrong_handle();
                return -1;
            }
            const int RANGE = 800;
            std::mt19937 generator(clock());
            std::uniform_int_distribution<int> uniform(0, RANGE);
            ofstream ouf("../testcase/" + filename);
            ouf << n << endl;
            for (int i = 0; i < n; i++) {
                int x = uniform(generator), y = uniform(generator);
                ouf << x << " " << y << endl;
            }
            ouf.close();
        } else {
            wrong_handle();
            return -1;
        }
    }
    return 0;
}
