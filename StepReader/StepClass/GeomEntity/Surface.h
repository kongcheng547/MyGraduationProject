//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_SURFACE_H
#define STEPREADER_SURFACE_H

#include "../SuperEntity.h"
#include "Curve.h"
#include "Point.h"
#include "MiddleGeom.h"

class Surface : public GeometricRepresentationItem {
public:
    Surface(string name) : GeometricRepresentationItem(name) {}

    virtual void getName() {}
};

class ElementarySurface : public Surface {
public:
    Axis2Placement3D position;

    ElementarySurface(string name, Axis2Placement3D position) : Surface(name), position(position) {}
};

class Plane : public ElementarySurface {
public:
    Plane(string name, Axis2Placement3D position) : ElementarySurface(name, position) {}

    static Plane handle(string fileRow, map<string, string> dataMap);
};

// 圆柱面
class CylindricalSurface : public ElementarySurface {
public:
    double radius;

    CylindricalSurface(string name, Axis2Placement3D position, double radius) : ElementarySurface(name, position),
                                                                                radius(radius) {}

    static CylindricalSurface handle(string fileRow, map<string, string> dataMap);
};

// 锥面
class ConicalSurface : public ElementarySurface {
public:
    double radius;
    // 圆锥半角
    double semiAngle;

    ConicalSurface(string name, Axis2Placement3D position, double radius, double semiAngle) : ElementarySurface(name,
                                                                                                                position),
                                                                                              radius(radius),
                                                                                              semiAngle(semiAngle) {}

    static ConicalSurface handle(string fileRow, map<string, string> dataMap);
};

// 球面
class SphericalSurface : public ElementarySurface {
public:
    double radius;

    SphericalSurface(string name, Axis2Placement3D position, double radius) : ElementarySurface(name, position),
                                                                              radius(radius) {}

    static SphericalSurface handle(string fileRow, map<string, string> dataMap);
};

// 环形面
class ToroidalSurface : public ElementarySurface {
public:
    double majorRadius;// 环面的大半径
    double minorRadius;// 环面的小半径
    ToroidalSurface(string name, Axis2Placement3D position, double majorRadius, double minorRadius) :
            ElementarySurface(name, position), majorRadius(majorRadius), minorRadius(minorRadius) {}

    static ToroidalSurface handle(string fileRow, map<string, string> dataMap);
};

// 杜平圆柱面
class DupinCyclideSurface : public ElementarySurface {

};

class SweptSurface : public Surface {

};

class BoundedSurface : public Surface {
public:
    BoundedSurface(string name) : Surface(name) {}
};

class BSplineSurface : public BoundedSurface {
public:
    int uDegree, vDegree;
    vector<vector<CartesianPoint>> controlPointsList;
    string surfaceForm;
    bool u_closed, v_closed, selfIntersect;

    BSplineSurface(string name) : BoundedSurface(name) {}
    BSplineSurface(string name, int uDegree, int vDegree, vector<vector<CartesianPoint>> controlPointList,
                   string surfaceForm,
                   bool u_closed, bool v_closed, bool selfIntersect) : BoundedSurface(name), uDegree(uDegree),
                                                                       vDegree(vDegree),
                                                                       controlPointsList(controlPointList),
                                                                       surfaceForm(surfaceForm), u_closed(u_closed),
                                                                       v_closed(v_closed),
                                                                       selfIntersect(selfIntersect) {}

    BSplineSurface(string name, BSplineSurface const &bSplineSurface) : BoundedSurface(name) {
        uDegree = bSplineSurface.uDegree;
        vDegree = bSplineSurface.vDegree;
        controlPointsList = bSplineSurface.controlPointsList;
        surfaceForm = bSplineSurface.surfaceForm;
        u_closed = bSplineSurface.u_closed;
        v_closed = bSplineSurface.v_closed;
        selfIntersect = bSplineSurface.selfIntersect;
    }

    static BSplineSurface handle(string fileRow, map<string, string> dataMap);

};

class BSplineSurfaceWithKnots : public BSplineSurface {
public:
    vector<int> u_multiplicities, v_multiplicities;
    vector<double> u_knots, v_knots;
    string knot_spec;

    BSplineSurfaceWithKnots(string name, vector<int> u_multiplicities, vector<int> v_multiplicities,
                            vector<double> u_knots,
                            vector<double> v_knots, string knot_spec) : BSplineSurface(name),
                                                                        u_multiplicities(u_multiplicities),
                                                                        v_multiplicities(v_multiplicities),
                                                                        u_knots(u_knots),
                                                                        v_knots(v_knots), knot_spec(knot_spec) {}

    BSplineSurfaceWithKnots(BSplineSurface bSplineSurface, vector<int> u_multiplicities, vector<int> v_multiplicities,
                            vector<double> u_knots,
                            vector<double> v_knots, string knot_spec) : BSplineSurface(bSplineSurface.name,
                                                                                       bSplineSurface),
                                                                        u_multiplicities(u_multiplicities),
                                                                        v_multiplicities(v_multiplicities),
                                                                        u_knots(u_knots),
                                                                        v_knots(v_knots), knot_spec(knot_spec) {}

    static BSplineSurfaceWithKnots handle(string fileRow, map<string, string> dataMap);
};

class RationalBSplineSurface : public BSplineSurface {
public:
    vector<vector<double>> weights;
    RationalBSplineSurface(string name, vector<vector<double>> weights) : BSplineSurface(name), weights(weights) {}

    static RationalBSplineSurface handle(string fileRow, map<string, string> dataMap);
};

class BSplineSurfaceSet : public BoundedSurface {
public:
    BSplineSurface bSplineSurface;
    BSplineSurfaceWithKnots bSplineSurfaceWithKnots;
    RationalBSplineSurface rationalBSplineSurface;
    BSplineSurfaceSet(string name, BSplineSurface bSplineSurface, BSplineSurfaceWithKnots bSplineSurfaceWithKnots,
                      RationalBSplineSurface rationalBSplineSurface) : BoundedSurface(name), bSplineSurface(bSplineSurface),
                                                                       bSplineSurfaceWithKnots(bSplineSurfaceWithKnots),
                                                                       rationalBSplineSurface(rationalBSplineSurface) {}
    static BSplineSurfaceSet handle(string fileRow, map<string, string> dataMap);
};

class OffsetSurface : public Surface {

};

class SurfaceReplica : public Surface {

};

#endif //STEPREADER_SURFACE_H
