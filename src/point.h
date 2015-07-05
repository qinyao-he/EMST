//
// Created by hqythu on 6/22/2015.
//

#ifndef EMST_POINT_H
#define EMST_POINT_H


class Point {
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    bool operator < (const Point& op) const;

    bool operator == (const Point& op) const;

    double distance(const Point& op) const;
};


#endif //EMST_POINT_H
