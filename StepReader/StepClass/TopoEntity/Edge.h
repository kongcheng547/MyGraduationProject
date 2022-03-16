//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_EDGE_H
#define STEPREADER_EDGE_H

#include "../SuperEntity.h"
#include "Vertex.h"
#include "../GeomEntity/Curve.h"

class Edge : public TopologicalRepresentationItem {
public:
    Edge(string name) : TopologicalRepresentationItem(name) {}
};

class EdgeCurve : public Edge {
public:
    VertexPoint startPoint, endPoint;
    Curve curve;
    bool isTheSameDir;

    EdgeCurve(string name, VertexPoint start, VertexPoint end, Curve curve1, bool isTheSame) : Edge(name),
                                                                                               startPoint(start),
                                                                                               endPoint(end),
                                                                                               curve(curve1) {
        this->isTheSameDir = isTheSame;
    }
};

class OrientedEdge : public Edge {
public:
    EdgeCurve edgeCurve;
    bool isTheSameDir;

    OrientedEdge(string name, EdgeCurve edgeCurve1, bool isTheSame) : Edge(name), edgeCurve(edgeCurve1) {
        this->isTheSameDir = isTheSame;
    }
};

#endif //STEPREADER_EDGE_H
