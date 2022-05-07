//
// Created by kongcheng547 on 2022/5/4.
//

#ifndef STEPREADER_GEOMPOINTER_H
#define STEPREADER_GEOMPOINTER_H
#include "../SuperEntity.h"
#include "../GeomEntity/Curve.h"
#include "../GeomEntity/Surface.h"

class GeomPointer {

};

class CurvePointer {
public:
    Curve *curve;
    string curveType;
    CurvePointer(Curve *curve, string curveType) : curve(curve), curveType(curveType) {}
//    ~CurvePointer();
    CurvePointer() {}
    static CurvePointer handle(string fileRow, map<string, string> dataMap);
    void DrawToObj(ofstream &outFile);
};

class SurfacePointer {
public:
    Surface *surface;
    string surfaceType;
    SurfacePointer(Surface *surface, string surfaceType) : surface(surface), surfaceType(surfaceType) {}

    SurfacePointer() {}

    static SurfacePointer handle(string fileRow, map<string, string> dataMap);
    void DrawToObj(ofstream &outFile);
};


#endif //STEPREADER_GEOMPOINTER_H
