//
// Created by hqythu on 6/22/2015.
//

#include "point.h"

#include <cmath>


double Point::distance(const Point& op) const
{
    double ret = 0;
    ret += (x - op.x) * (x - op.x);
    ret += (y - op.y) * (y - op.y);
    return sqrt(ret);
}


bool Point::operator < (const Point &op) const {
    if (x < op.x) {
        return true;
    } else if (x > op.x) {
        return false;
    } else{
        if (y < op.y) {
            return true;
        } else {
            return false;
        }
    }
}
