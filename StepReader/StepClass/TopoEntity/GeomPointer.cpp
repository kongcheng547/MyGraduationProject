//
// Created by kongcheng547 on 2022/5/4.
//

#include "GeomPointer.h"

//CurvePointer::~CurvePointer() {
//    delete curve;
//    curve = NULL;
//}

CurvePointer CurvePointer::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("RATIONAL_B_SPLINE_CURVE") != string::npos
        && fileRow.find("B_SPLINE_CURVE") != string::npos
        && fileRow.find("B_SPLINE_CURVE_WITH_KNOTS") != string::npos) {
        string type = "BSplineCurveSet";
        BSplineCurveSet curve = BSplineCurveSet::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new BSplineCurveSet(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("B_SPLINE_CURVE_WITH_KNOTS") != string::npos) {
        string type = "B_SPLINE_CURVE_WITH_KNOTS";
        BSplineCurveWithKnots curve = BSplineCurveWithKnots::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new BSplineCurveWithKnots(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("RATIONAL_B_SPLINE_CURVE") != string::npos) {
        string type = "RATIONAL_B_SPLINE_CURVE";
        RationalBSplineCurve curve = RationalBSplineCurve::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new RationalBSplineCurve(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("B_SPLINE_CURVE") != string::npos) {
        string type = "B_SPLINE_CURVE";
        BSplineCurve curve = BSplineCurve::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new BSplineCurve(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("LINE") != string::npos) {
        string type = "LINE";
        Line curve = Line::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new Line(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("CIRCLE") != string::npos) {
        string type = "CIRCLE";
        Circle curve = Circle::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new Circle(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("ELLIPSE") != string::npos) {
        string type = "ELLIPSE";
        Ellipse curve = Ellipse::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new Ellipse(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("HYPERBOLA") != string::npos) {
        string type = "HYPERBOLA";
        Hyperbola curve = Hyperbola::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new Hyperbola(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else if (fileRow.find("PARABOLA") != string::npos) {
        string type = "PARABOLA";
        Parabola curve = Parabola::handle(fileRow, dataMap);
        CurvePointer curvePointer;
        curvePointer.curve = new Parabola(curve);
        curvePointer.curveType = type;
        return curvePointer;
    } else {
        cout << "本条" + fileRow + "不是本程序可以处理的曲线" << endl;
        exit(0);
        getchar();
    }
}

void CurvePointer::DrawToObj(ofstream &outFile) {

}

SurfacePointer SurfacePointer::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("PLANE") != string::npos) {
        SurfacePointer surfacePointer;
        Plane surface = Plane::handle(fileRow, dataMap);
        surfacePointer.surface = new Plane(surface);
        surfacePointer.surfaceType = "PLANE";
        return surfacePointer;
    } else if (fileRow.find("CYLINDRICAL_SURFACE") != string::npos) {
        SurfacePointer surfacePointer;
        CylindricalSurface surface = CylindricalSurface::handle(fileRow, dataMap);
        surfacePointer.surface = new CylindricalSurface(surface);
        surfacePointer.surfaceType = "CYLINDRICAL_SURFACE";
        return surfacePointer;
    } else if (fileRow.find("CONICAL_SURFACE") != string::npos) {
        SurfacePointer surfacePointer;
        ConicalSurface surface = ConicalSurface::handle(fileRow, dataMap);
        surfacePointer.surface = new ConicalSurface(surface);
        surfacePointer.surfaceType = "CONICAL_SURFACE";
        return surfacePointer;
    } else if (fileRow.find("SPHERICAL_SURFACE") != string::npos) {
        SurfacePointer surfacePointer;
        SphericalSurface surface = SphericalSurface::handle(fileRow, dataMap);
        surfacePointer.surface = new SphericalSurface(surface);
        surfacePointer.surfaceType = "SPHERICAL_SURFACE";
        return surfacePointer;
    } else if (fileRow.find("TOROIDAL_SURFACE") != string::npos) {
        SurfacePointer surfacePointer;
        ToroidalSurface surface = ToroidalSurface::handle(fileRow, dataMap);
        surfacePointer.surface = new ToroidalSurface(surface);
        surfacePointer.surfaceType = "TOROIDAL_SURFACE";
        return surfacePointer;
    } else if (fileRow.find("RATIONAL_B_SPLINE_SURFACE") != string::npos &&
               fileRow.find("B_SPLINE_SURFACE") != string::npos
               && fileRow.find("B_SPLINE_SURFACE_WITH_KNOTS") != string::npos) {
        SurfacePointer surfacePointer;
        BSplineSurfaceSet surface = BSplineSurfaceSet::handle(fileRow, dataMap);
        surfacePointer.surface = new BSplineSurfaceSet(surface);
        surfacePointer.surfaceType = "BSplineSurfaceSet";
        return surfacePointer;
    } else if (fileRow.find("B_SPLINE_SURFACE_WITH_KNOTS") != string::npos) {
        SurfacePointer surfacePointer;
        BSplineSurfaceWithKnots surface = BSplineSurfaceWithKnots::handle(fileRow, dataMap);
        surfacePointer.surface = new BSplineSurfaceWithKnots(surface);
        surfacePointer.surfaceType = "B_SPLINE_SURFACE_WITH_KNOTS";
        return surfacePointer;
    } else if (fileRow.find("RATIONAL_B_SPLINE_SURFACE") != string::npos) {
        SurfacePointer surfacePointer;
        RationalBSplineSurface surface = RationalBSplineSurface::handle(fileRow, dataMap);
        surfacePointer.surface = new RationalBSplineSurface(surface);
        surfacePointer.surfaceType = "RATIONAL_B_SPLINE_SURFACE";
        return surfacePointer;
    } else if (fileRow.find("B_SPLINE_SURFACE") != string::npos) {
        SurfacePointer surfacePointer;
        BSplineSurface surface = BSplineSurface::handle(fileRow, dataMap);
        surfacePointer.surface = new BSplineSurface(surface);
        surfacePointer.surfaceType = "B_SPLINE_SURFACE";
        return surfacePointer;
    } else {
        cout << "本条" + fileRow + "不是本程序可以处理的曲面，请检查格式" << endl;
        exit(0);
        getchar();
    }
}

void SurfacePointer::DrawToObj(ofstream &outFile) {
    if (this->surfaceType == "PLANE") {
        auto *surface = dynamic_cast<Plane*>(this->surface);
        surface->DrawToObj(outFile);
    }
}
