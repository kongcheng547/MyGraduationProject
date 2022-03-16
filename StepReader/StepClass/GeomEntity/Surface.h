//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_SURFACE_H
#define STEPREADER_SURFACE_H

#include "../SuperEntity.h"
#include "Curve.h"
#include "Point.h"

class Surface : public GeometricRepresentationItem {
public:
    Surface(string name) : GeometricRepresentationItem(name) {}
};

class ElementarySurface : public Surface {
public:
    ElementarySurface(string name) : Surface(name) {}
};

class Axis2Placement3D : public Surface {
public:
    // 定位点、法线、参考方向
    CartesianPoint locPoint;
    Direction normal, referenceDirection;

    Axis2Placement3D(string name, CartesianPoint locPoint1, Direction normalLine,
                     Direction referenceDirection) : Surface(name), locPoint(locPoint1), normal(normalLine),
                                                     referenceDirection(referenceDirection) {}
};

class Plane : public ElementarySurface {
public:
    Axis2Placement3D axisPlane;
    Plane(string name, Axis2Placement3D axis2Placement3D) : ElementarySurface(name), axisPlane(axis2Placement3D){}

};

class SweptSurface : public ElementarySurface {

};

class BoundedSurface : public ElementarySurface {

};

class OffsetSurface : public ElementarySurface {

};

class SurfaceReplica : public ElementarySurface {

};
#endif //STEPREADER_SURFACE_H
