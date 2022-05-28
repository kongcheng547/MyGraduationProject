//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_EDGE_H
#define STEPREADER_EDGE_H

#include "../SuperEntity.h"
#include "Vertex.h"
#include "../GeomEntity/Curve.h"
#include "GeomPointer.h"

class Edge : public TopologicalRepresentationItem {
public:
    Edge(string name) : TopologicalRepresentationItem(name) {}
};

class EdgeCurve : public Edge {
public:
    VertexPoint startPoint, endPoint;   // 起点和终点
    CurvePointer curve; // 几何曲线
    bool isTheSameDir;  // 最后结果是否和几何曲线方向一致
    EdgeCurve(string name, VertexPoint start, VertexPoint end, CurvePointer curve, bool isTheSame) : Edge(name),
                                                                                               startPoint(start),
                                                                                               endPoint(end),
                                                                                               curve(curve) {
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
