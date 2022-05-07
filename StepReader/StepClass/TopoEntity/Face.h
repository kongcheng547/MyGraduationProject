//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_FACE_H
#define STEPREADER_FACE_H

#include "../SuperEntity.h"
#include "Edge.h"
#include "Loop.h"
#include "../GeomEntity/Surface.h"

class Face : public TopologicalRepresentationItem {
public:
    Face(string name) : TopologicalRepresentationItem(name) {}
};

class FaceOuterBound : public TopologicalRepresentationItem {
public:
    EdgeLoop edgeLoop;
    bool isTheSameDir;

    FaceOuterBound(string name, EdgeLoop edgeLoop1, bool isTheSame) : TopologicalRepresentationItem(name),
                                                                      edgeLoop(edgeLoop1), isTheSameDir(isTheSame) {}
    static FaceOuterBound handle(string fileRow, map<string, string> dataMap);
};

class AdvancedFace : public Face {
public:
    vector<FaceOuterBound> boundVector;
    SurfacePointer face;
    bool isTheSameDir;

    AdvancedFace(string name, vector<FaceOuterBound> boundVector1,
                 SurfacePointer face, bool isTheSame) : Face(name),
                                                  boundVector(boundVector1),
                                                  face(face),
                                                  isTheSameDir(isTheSame) {}
    static AdvancedFace handle(string fileRow, map<string, string> dataMap);
    void DrawToObj(ofstream &outFile);
};

class FaceSurface : public Face {

};

class OrientedFace : public Face {

};

#endif //STEPREADER_FACE_H
