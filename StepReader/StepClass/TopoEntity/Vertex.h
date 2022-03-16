//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_VERTEX_H
#define STEPREADER_VERTEX_H
#include "../SuperEntity.h"
#include "../GeomEntity/Point.h"

class Vertex : public TopologicalRepresentationItem {
public:
    Vertex(string name) : TopologicalRepresentationItem(name) {}
};

class VertexPoint : public Vertex {
public:
    CartesianPoint cartesianPoint;
    VertexPoint(string name, CartesianPoint cartesianPoint1) : Vertex(name), cartesianPoint(cartesianPoint1) {}
};


#endif //STEPREADER_VERTEX_H
