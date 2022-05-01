//
// Created by kongcheng547 on 2022/4/28.
//

#ifndef STEPREADER_MIDDLEGEOM_H
#define STEPREADER_MIDDLEGEOM_H
#include "../SuperEntity.h"
#include "Point.h"

class MiddleGeom {

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

class Placement : public GeometricRepresentationItem {
public:
    CartesianPoint locPoint;
    Placement(string name, CartesianPoint locPoint1) : GeometricRepresentationItem(name), locPoint(locPoint1) { }
//    static virtual Placement handle(string fileRow, map<string, string> dataMap);
};

class Axis2Placement3D : public Placement {
public:
    // 定位点、法线、参考方向
    Direction normal, referenceDirection;
    Axis2Placement3D(string name, CartesianPoint locPoint1, Direction normalLine,
                     Direction referenceDirection) : Placement(name, locPoint1), normal(normalLine),
                                                     referenceDirection(referenceDirection) {}
    static Axis2Placement3D handle(string fileRow, map<string, string> dataMap);
};





#endif //STEPREADER_MIDDLEGEOM_H
