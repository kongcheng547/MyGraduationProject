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

    static Direction handle(string fileRow, map<string, string> dataMap);
};

class Vector : public GeometricRepresentationItem {
public:
    Direction direction;
    double length;

    Vector(string name, Direction direction1, double length) : GeometricRepresentationItem(name),
                                                               direction(direction1) {
        this->length = length;
    }

    static Vector handle(string fileRow, map<string, string> dataMap);
};

class Line : public Curve {
public:
    Vector vec;
    CartesianPoint cartesianPoint;

    Line(string name, CartesianPoint cartesianPoint1, Vector vector1) : Curve(name), vec(vector1),
                                                                        cartesianPoint(cartesianPoint1) {}
    static Line handle(string fileRow, map<string, string> dataMap);
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
