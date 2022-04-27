//
// Created by kongcheng547 on 2022/3/14.
//

#ifndef STEPREADER_STEPFILE_H
#define STEPREADER_STEPFILE_H

#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "fstream"
#include "../Util/Util.h"
#include "../StepClass/GeomEntity/ManifoldSolidBrep.h"

using namespace std;
class StepFile {
public:
    string standardNum;
    string fileHeader;
    string data;
    map<string, string> dataMap;
    vector<string> manifoldString;
    vector<ManifoldSolidBrep> manifoldSolidBrepVec;
    StepFile() = default;
    void readFile(string filePath);
    void handleData();
};


#endif //STEPREADER_STEPFILE_H
