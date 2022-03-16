//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_POINT_H
#define STEPREADER_POINT_H

#include "iostream"
#include "..\SuperEntity.h"
#include "string"

using namespace std;

class Point : public GeometricRepresentationItem {
public:
    Point(string name) : GeometricRepresentationItem(name) {}
};

class CartesianPoint : public Point {
public:
    double x;
    double y;
    double z;

    CartesianPoint(string name, double x, double y, double z) : Point(name) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

};

//（曲线上的点）
class PointOnCurve : public Point {

};

//（曲面上的点）
class PointOnSurface : public Point {
};

//（复制点）
class PointReplica : public Point {
};

//（退化曲线的点）
class DegeneratePcurve : public Point {
};

#endif //STEPREADER_POINT_H
