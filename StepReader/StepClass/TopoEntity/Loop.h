//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_LOOP_H
#define STEPREADER_LOOP_H

#include "../SuperEntity.h"
#include "Vertex.h"
#include "Edge.h"

class Loop : public TopologicalRepresentationItem{
public:
    Loop(string name) : TopologicalRepresentationItem(name) {}
};

class VertexLoop : public Loop {
public:
    VertexLoop(string name) : Loop(name) {}
};

class EdgeLoop : public Loop {
public:
    vector<OrientedEdge> orientedEdgeVector;
    EdgeLoop(string name, vector<OrientedEdge> vector1) : Loop(name), orientedEdgeVector(vector1) {}
    static EdgeLoop handle(string fileRow, map<string, string> dataMap);
};

class PolyLoop : public Loop {
public:
    PolyLoop(string name) : Loop(name) {}
};

#endif //STEPREADER_LOOP_H
