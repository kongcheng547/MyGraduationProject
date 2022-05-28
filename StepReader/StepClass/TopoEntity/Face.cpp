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
        // 边界是起点和终点，里面点可能被重复使用，所以要用set集合去重
        set<CartesianPoint> pointSet;
        for (int i = 0; i < this->boundVector.size(); i++) {
            for (int j = 0; j < this->boundVector[i].edgeLoop.orientedEdgeVector.size(); j++) {
                // 对每一个边界找到它的起点，如果不存在集合中就加进去
                CartesianPoint tempPoint = this->boundVector[i].edgeLoop.orientedEdgeVector[j].edgeCurve.startPoint.locPoint;
                if (pointSet.find(tempPoint) == pointSet.end()) {
                    pointSet.insert(tempPoint);
                }
                // 对每一个边界找到它的终点，如果不存在集合中就加进去
                tempPoint = this->boundVector[i].edgeLoop.orientedEdgeVector[j].edgeCurve.endPoint.locPoint;
                if (pointSet.find(tempPoint) == pointSet.end()) {
                    pointSet.insert(tempPoint);
                }
            }
        }
        vector<CartesianPoint> sortVec;
        // 将点放入vector方便后续操作
        sortVec.assign(pointSet.begin(), pointSet.end());
        // 选择离前一个最近的节点作为连接 因为obj文件中连接顺序不对会导致面绘制错误
        // 用了选择排序的方法，总是找到离当前节点最近的一个点作为下一个点
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
        // 输出到obj文件中
        for (int i = 0; i < sortVec.size(); i++) {
            outFile << "v " << sortVec[i].x << ' ' << sortVec[i].y << ' ' << sortVec[i].z << endl;
        }
        // 输出面的定义
        outFile << "f";
        for (int i = pointSet.size(); i >= 1; i--) {
            outFile << ' ' + to_string(-i);
        }
        outFile << endl;
    } else if (this->face.surfaceType == "CYLINDRICAL_SURFACE") {
        DrawUtil drawUtil;
        vector<vector<double>> circle1, circle2;
        vector<OrientedEdge> orientedVec = this->boundVector[0].edgeLoop.orientedEdgeVector;
        int index = -1;
        for (int i = 0; i < orientedVec.size(); i++) {
            if (orientedVec[i].edgeCurve.curve.curveType == "CIRCLE") {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return ;
        }
        Circle *c1 = dynamic_cast<Circle*>(orientedVec[index].edgeCurve.curve.curve);
        double norm1[] = {c1->position.normal.x, c1->position.normal.y, c1->position.normal.z};
        circle1 = drawUtil.handleCircle(c1, 1);
        index = 0;
        for (int i = orientedVec.size() - 1; i >= 1; i--) {
            if (orientedVec[i].edgeCurve.curve.curveType == "CIRCLE") {
                index = i;
                break;
            }
        }
        if (index == 0 || orientedVec[index].edgeCurve.curve.curveType != "CIRCLE") {
            return ;
        }
        Circle *c2 = dynamic_cast<Circle*>(orientedVec[index].edgeCurve.curve.curve);
        double norm2[] = {c2->position.normal.x, c2->position.normal.y, c2->position.normal.z};
        int normNum = (norm1[0] * norm2[0] + norm1[1] * norm2[1] + norm1[2] * norm2[2]) > 0 ? 1 : -1;
        circle2 = drawUtil.handleCircle(c2, normNum);
        for (int i = 0; i < circle1.size(); i++) {
            outFile << "v " << circle1[i][0] << ' ' << circle1[i][1] << ' ' << circle1[i][2] << endl;
        }
        for (int i = 0; i < circle2.size(); i++) {
            outFile << "v " << circle2[i][0] << ' ' << circle2[i][1] << ' ' << circle2[i][2] << endl;
        }
        int size1 = circle1.size(), size2 = circle2.size();
        int center1 = -(size1 + size2), center2 = -size2;
        for (int i = 1; i < size1 - 1; i++) {
            outFile << "f " << center1 << " " << center1 + i << " " << center1 + i + 1 << endl;
        }
        outFile << "f " << center1 << " " << center1 + size1 - 1 << " " << center1 + 1 << endl;
        for (int i = 1; i < size2 - 1; i++) {
            outFile << "f " << center2 << " " << center2 + i << " " << center2 + i + 1 << endl;
        }
        outFile << "f " << center2 << " " << center2 + size2 - 1 << " " << center2 + 1 << endl;

        for (int i = 1; i < size1 - 1; i++) {
            outFile << "f " << center1 + i << " " << center2 + i << ' ' << center2 + i + 1 << ' ' << center1 + i + 1 << endl;
        }
        outFile << "f " << center2 - 1 << " " << -1 << ' ' << center2 + 1 << ' ' << center1 + 1 << endl;
    }
}
