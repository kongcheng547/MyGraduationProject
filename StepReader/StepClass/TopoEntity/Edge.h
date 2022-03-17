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
    Line line;
    bool isTheSameDir;
    // TODO:暂时先全都用line代替，后面记得要改
    EdgeCurve(string name, VertexPoint start, VertexPoint end, Line line, bool isTheSame) : Edge(name),
                                                                                               startPoint(start),
                                                                                               endPoint(end),
                                                                                               line(line) {
        this->isTheSameDir = isTheSame;
    }

    static EdgeCurve handle(string fileRow, map<string, string> dataMap);
};

class OrientedEdge : public Edge {
public:
    EdgeCurve edgeCurve;
    bool isTheSameDir;

    OrientedEdge(string name, EdgeCurve edgeCurve1, bool isTheSame) : Edge(name), edgeCurve(edgeCurve1) {
        this->isTheSameDir = isTheSame;
    }

    static OrientedEdge handle(string fileRow, map<string, string> dataMap);
};

#endif //STEPREADER_EDGE_H
