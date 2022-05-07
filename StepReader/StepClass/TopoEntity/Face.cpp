//
// Created by kongcheng547 on 2022/3/7.
//

#include "Face.h"

//#235202 = FACE_BOUND ( 'NONE', #750103, .T. ) ;
//#73 = FACE_OUTER_BOUND ( 'NONE', #188, .T. ) ;
FaceOuterBound FaceOuterBound::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("FACE_OUTER_BOUND") == string::npos && fileRow.find("FACE_BOUND") == string::npos) {
        cout << "本条" + fileRow + "不是FACE_OUTER_BOUND，请检查文件格式" << endl;
        getchar();
        exit(0);
    }
    vector<string> tempSplitVec;
    Util util;
    util.split(fileRow, tempSplitVec, ',');
    regex re("[\\'](.*?)[\\']");
    smatch m;
    regex_search(tempSplitVec[0], m, re);
    string name = m.str(0).substr(1, m.str(0).length() - 2);
    if (name == "NONE") {
        name = "";
    }
    tempSplitVec[2] = tempSplitVec[2][1];
    EdgeLoop edgeLoop = EdgeLoop::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    bool isTheSameDir = tempSplitVec[2] == "T";
    return {name, edgeLoop, isTheSameDir};
}

//#56 = ADVANCED_FACE ( 'NONE', ( #73 ), #101, .T. ) ;
AdvancedFace AdvancedFace::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("ADVANCED_FACE") == string::npos) {
        cout << "本条" + fileRow + "不是ADVANCED_FACE，请检查文件格式" << endl;
        getchar();
        exit(0);
    }
    vector<string> tempSplitVec;
    Util util;
    util.split(fileRow, tempSplitVec, ',');
    regex re("[\\'](.*?)[\\']");
    smatch m;
    regex_search(tempSplitVec[0], m, re);
    string name = m.str(0).substr(1, m.str(0).length() - 2);
    if (name == "NONE") {
        name = "";
    }
    tempSplitVec[1] = util.clearSelectedChar(tempSplitVec[1], '(');
    tempSplitVec[tempSplitVec.size() - 3] = util.clearSelectedChar(tempSplitVec[tempSplitVec.size() - 3], ')');
    vector<FaceOuterBound> boundVector;
    for (int i = 1; i <= tempSplitVec.size() - 3; i++) {
        boundVector.push_back(FaceOuterBound::handle(dataMap.find(tempSplitVec[i])->second, dataMap));
    }
    SurfacePointer surface = SurfacePointer::handle(dataMap.find(tempSplitVec[tempSplitVec.size() - 2])->second,
                                                    dataMap);
    bool isTheSameDir = tempSplitVec[tempSplitVec.size() - 1].find('F') == string::npos;
    return {name, boundVector, surface, isTheSameDir};
}

void AdvancedFace::DrawToObj(ofstream &outFile) {
    if (this->face.surfaceType == "PLANE") {
        set<CartesianPoint> pointSet;
        for (int i = 0; i < this->boundVector.size(); i++) {
            for (int j = 0; j < this->boundVector[i].edgeLoop.orientedEdgeVector.size(); j++) {
                CartesianPoint tempPoint = this->boundVector[i].edgeLoop.orientedEdgeVector[j].edgeCurve.startPoint.locPoint;
                if (pointSet.find(tempPoint) == pointSet.end()) {
                    pointSet.insert(tempPoint);
                }
                tempPoint = this->boundVector[i].edgeLoop.orientedEdgeVector[j].edgeCurve.endPoint.locPoint;
                if (pointSet.find(tempPoint) == pointSet.end()) {
                    pointSet.insert(tempPoint);
                }
            }
        }
        vector<CartesianPoint> sortVec;
        sortVec.assign(pointSet.begin(), pointSet.end());
        // 选择离前一个最近的节点作为连接
        for (int i = 0; i < sortVec.size() - 1; i++) {
            double minDistance = 1000000000;
            int index = i + 1;
            for (int j = i + 1; j < sortVec.size(); j++) {
                double distance = (pow(sortVec[i].x - sortVec[j].x, 2) + pow(sortVec[i].y - sortVec[j].y, 2) +
                                   pow(sortVec[i].z - sortVec[j].z, 2));
                if (minDistance > distance) {
                    index = j;
                    minDistance = distance;
                }
            }
            CartesianPoint temp = sortVec[i + 1];
            sortVec[i + 1] = sortVec[index];
            sortVec[index] = temp;
        }
        for (int i = 0; i < sortVec.size(); i++) {
            outFile << "v " << sortVec[i].x << ' ' << sortVec[i].y << ' ' << sortVec[i].z << endl;
        }
        outFile << "f";
        for (int i = pointSet.size(); i >= 1; i--) {
            outFile << ' ' + to_string(-i);
        }
        outFile << endl;
    }
}
