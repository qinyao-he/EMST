# CornerBlockList
Course Project for Object Oriented Programming in Tsinghua University. Solving the Euclidean Minimal Spanning Tree.

Using CMake as building tools.

src directory contains source code of the main project. test directory contain test code.
testcase directory contain 5 files as random generated test data to be used in test program.

In cmake in configure 2 executive. EMST is the main program. Running without parameter will random generate 500
point and run Delaunay algorithm on them and plot the final result. You can also specify a input data file using
parameter.

EMST_Test is the test program, using testcases to test whether Delaunay produce the same result as the
brute-force Prim algorithm. Running without parameter will start testing. You may specify parameter as
'generate n filname' to generate new data files. However, testing program only use input1.txt to input5.txt as test
data.