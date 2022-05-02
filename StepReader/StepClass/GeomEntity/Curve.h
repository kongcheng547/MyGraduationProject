//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_CURVE_H
#define STEPREADER_CURVE_H

#include "../SuperEntity.h"
#include "Point.h"
#include "MiddleGeom.h"

class Curve : public GeometricRepresentationItem {
public:
    Curve(string name) : GeometricRepresentationItem(name) {}

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
public:
    Axis2Placement3D position;

    Conic(string name, Axis2Placement3D position) : Curve(name), position(position) {}
};

//Ô²
class Circle : public Conic {
public:
    double radius;

    Circle(string name, Axis2Placement3D position, double radius) : Conic(name, position), radius(radius) {}

    static Circle handle(string fileRow, map<string, string> dataMap);
};

// ÍÖÔ²
class Ellipse : public Conic {
public:
    double semiAxis1, semiAxis2;

    Ellipse(string name, Axis2Placement3D position, double semiAxis1, double semiAxis2)
            : Conic(name, position), semiAxis1(semiAxis1), semiAxis2(semiAxis2) {}

    static Ellipse handle(string fileRow, map<string, string> dataMap);
};

// Ë«ÇúÏß
class Hyperbola : public Conic {
public:
    // ÊµÖáºÍÐéÖá
    double semiAxis, semiImagAxis;

    Hyperbola(string name, Axis2Placement3D position, double semiAxis, double SemiImagAxis) : Conic(name, position),
                                                                                              semiAxis(semiAxis),
                                                                                              semiImagAxis(
                                                                                                      semiImagAxis) {}

    static Hyperbola handle(string fileRow, map<string, string> dataMap);
};

// Å×ÎïÏß
class Parabola : public Conic {
public:
    // ½¹¾à
    double focalDist;

    Parabola(string name, Axis2Placement3D position, double focalDist) : Conic(name, position), focalDist(focalDist) {}

    static Parabola handle(string fileRow, map<string, string> dataMap);
};

class Clothoid : public Curve {

};

class CircularInvolute : public Curve {

};

class Pcurve : public Curve {

};


class BoundedCurve : public Curve {
public:
    BoundedCurve(string name) : Curve(name) {}
};

class Polyline : public BoundedCurve {

};

class BSplineCurve : public BoundedCurve {
public:
    int degree;
    vector<CartesianPoint> controlPointsList;
    string curveForm;
    bool isClosedCurve, isSelfIntersect;

    BSplineCurve(string name) : BoundedCurve(name) {}

    BSplineCurve(string name, int degree, vector<CartesianPoint> controlPointsList, string curveForm,
                 bool isClosedCurve, bool isSelfIntersect) : BoundedCurve(name), degree(degree),
                                                             controlPointsList(controlPointsList),
                                                             curveForm(curveForm), isClosedCurve(isClosedCurve),
                                                             isSelfIntersect(isSelfIntersect) {}

    BSplineCurve(string name, BSplineCurve bSplineCurve) : BoundedCurve(name) {
        this->degree = bSplineCurve.degree;
        this->controlPointsList = bSplineCurve.controlPointsList;
        this->curveForm = bSplineCurve.curveForm;
        this->isClosedCurve = bSplineCurve.isClosedCurve;
        this->isSelfIntersect = bSplineCurve.isSelfIntersect;
    }

    static BSplineCurve handle(string fileRow, map<string, string> dataMap);

};

class UniformCurve : public BSplineCurve {

};

class BSplineCurveWithKnots : public BSplineCurve {
public:
    vector<int> knotMultiplicities;
    vector<double> knots;
    string knotSpec;

    BSplineCurveWithKnots(string name, vector<int> knotMultiplicities, vector<double> knots, string knotSpec) :
            BSplineCurve(name), knotMultiplicities(knotMultiplicities), knots(knots), knotSpec(knotSpec) {}

    BSplineCurveWithKnots(BSplineCurve bSplineCurve, vector<int> knotMultiplicities, vector<double> knots,
                          string knotSpec) :
            BSplineCurve(bSplineCurve.name, bSplineCurve), knotMultiplicities(knotMultiplicities), knots(knots),
            knotSpec(knotSpec) {}

    static BSplineCurveWithKnots handle(string fileRow, map<string, string> dataMap);
};

class QuasiUniformCurve : public BSplineCurve {

};

class BezierCurve : public BSplineCurve {

};

class RationalBSplineCurve : public BSplineCurve {
public:
    vector<double> weightsData;

    RationalBSplineCurve(string name, vector<double> weightsData) : BSplineCurve(name), weightsData(weightsData) {}

    static RationalBSplineCurve handle(string fileRow, map<string, string> dataMap);
};

class BSplineCurveSet : public BoundedCurve {
public:
    BSplineCurve bSplineCurve;
    BSplineCurveWithKnots bSplineCurveWithKnots;
    RationalBSplineCurve rationalBSplineCurve;

    BSplineCurveSet(string name, BSplineCurve bSplineCurve, BSplineCurveWithKnots bSplineCurveWithKnots,
                    RationalBSplineCurve rationalBSplineCurve) : BoundedCurve(name), bSplineCurve(bSplineCurve),
                                                                 bSplineCurveWithKnots(bSplineCurveWithKnots),
                                                                 rationalBSplineCurve(rationalBSplineCurve) {}

    static BSplineCurveSet handle(string fileRow, map<string, string> dataMap);
};

class TrimmedCurve : public BoundedCurve {

};

class BoundedPcurve : public BoundedCurve, public Pcurve {

};

class BoundedSurfaceCurve : public BoundedCurve {

};

class CompositeCurve : public BoundedCurve {

};

class LocallyRefinedSplineCurve : public BoundedCurve {

};

class SurfaceCurve : public Curve {

};

class OffsetCurve2D : public Curve {

};

class OffsetCurve3D : public Curve {

};

class CurveReplica : public Curve {

};

#endif //STEPREADER_CURVE_H
