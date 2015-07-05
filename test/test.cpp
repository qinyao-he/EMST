#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <random>


using std::cout;
using std::endl;
using std::ofstream;
using std::string;


inline void wrong_handle()
{
    cout << "Bad command." << endl;
    cout << "Run with out parameter to test, or 'generate number filename' to generate testcase." << endl;
}


int main(int argc, char** argv)
{
    if (argc == 1) {

    } else {
        bool wrong = false;
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
