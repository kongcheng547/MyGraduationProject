//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_CLOSEDSHELL_H
#define STEPREADER_CLOSEDSHELL_H
#include "../SuperEntity.h"
#include "Face.h"

class ClosedShell : public TopologicalRepresentationItem{
public:
    vector<Face> faceVector;
    ClosedShell(string name, vector<Face> faceVector1) : TopologicalRepresentationItem(name), faceVector(faceVector1) {}
};


#endif //STEPREADER_CLOSEDSHELL_H
