//
// Created by kongcheng547 on 2022/3/14.
//

#include "StepFile.h"

void StepFile::readFile(string filePath) {
    fstream infile;
    infile.open(filePath, ios::in);
    if (!infile)
    {
        cerr << "open file " + filePath + " failed!" << endl;
        exit(1);
    }
    string line;
    bool isFirst = false;
    bool isHead = false;
    bool isData = false;
    while (getline(infile, line)) {
        if (!isFirst) { // 第一行是标准标号
            this->standardNum = line;
            isFirst = true;
            continue;
        }
        if (line.find("ENDSEC") != string::npos) {
            isData = false;
            isHead = false;
        }
        if (line.find("HEADER;") != string::npos) {
            isHead = true;
            continue;
        }
        if (line.find("DATA;") != string::npos) {
            isData = true;
            continue;
        }
        if (isHead) {
            this->fileHeader += line;
            continue;
        }
        if (isData) {
            this->data += line;
        }
    }
}

void StepFile::handleData() {
    vector<string> dataStringVector;
    Util util;
    util.split(this->data, dataStringVector, ';');
    unsigned long len = dataStringVector.size();
    for (int i = 0; i < len - 1; i++) {
        string line1 = util.clearSelectedChar(dataStringVector[i], ' ');
        string line = util.clearSelectedChar(line1, '\r');
//        line = line.substr(0, line.length() - 1);
        vector<string> tempStringVec;
        util.split(line, tempStringVec, '=');
        if (line.find("MANIFOLD_SOLID_BREP") != string::npos) {
            this->manifoldString.push_back(tempStringVec[0]);
        }
        // dataMap key是每行的标号，带#号，value是整行去掉空格之后的结果
        this->dataMap.insert(pair<string,string>(tempStringVec[0], line));
    }
}
