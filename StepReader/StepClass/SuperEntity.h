//
// Created by kongcheng547 on 2022/3/6.
//

#ifndef STEPREADER_SUPERENTITY_H
#define STEPREADER_SUPERENTITY_H

#include <utility>

#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "../Util/Util.h"
#include "regex"
#include "sstream"
#include "fstream"
#include "set"
#include <cmath>

using namespace std;

// 是所有数据结构类的超类
class RepresentationItem {
public:
    string name;

    explicit RepresentationItem(string name) {
        this->name = std::move(name);
    }
};

// 是几何实体的超类
class GeometricRepresentationItem : public RepresentationItem {
public:
    GeometricRepresentationItem(string name) : RepresentationItem(name) {}
};

// 拓扑实体的超类
class TopologicalRepresentationItem : public RepresentationItem {
public:
    explicit TopologicalRepresentationItem(string name) : RepresentationItem(name) {}
};

#endif //STEPREADER_SUPERENTITY_H
