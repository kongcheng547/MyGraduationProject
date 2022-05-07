//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_CLOSEDSHELL_H
#define STEPREADER_CLOSEDSHELL_H
#include "../SuperEntity.h"
#include "Face.h"

class ClosedShell : public TopologicalRepresentationItem{
public:
    // TODO:先用advancedFace做代替
    vector<AdvancedFace> faceVector;
    ClosedShell(string name, vector<AdvancedFace> faceVector1) : TopologicalRepresentationItem(name), faceVector(faceVector1) {}

    static ClosedShell handle(string fileRow, map<string, string> dataMap);

    void DrawToObj(ofstream &outFile);
};


#endif //STEPREADER_CLOSEDSHELL_H
