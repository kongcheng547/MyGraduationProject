//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_CURVE_H
#define STEPREADER_CURVE_H

#include "../SuperEntity.h"
#include "Point.h"

class Curve : public GeometricRepresentationItem {
public:
    Curve(string name) : GeometricRepresentationItem(name) {}
};

class Direction : public GeometricRepresentationItem {
public:
    double x, y, z;

    Direction(string name, double x, double y, double z) : GeometricRepresentationItem(name) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class Vector : public GeometricRepresentationItem {
public:
    Direction direction;
    double length;

    Vector(string name, Direction direction1, double length) : GeometricRepresentationItem(name),
                                                               direction(direction1) {
        this->length = length;
    }
};

class Line : public Curve {
public:
    Vector vector;
    CartesianPoint cartesianPoint;

    Line(string name, Vector vector1, CartesianPoint cartesianPoint1) : Curve(name), vector(vector1),
                                                                        cartesianPoint(cartesianPoint1) {}
};

class Conic : public Curve {

};

class Pcurve : public Curve{

};

class OffsetCurve3D : public Curve {

};

class CurveReplica : public Curve {

};
#endif //STEPREADER_CURVE_H
