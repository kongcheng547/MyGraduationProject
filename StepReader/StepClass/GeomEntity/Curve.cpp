//
// Created by kongcheng547 on 2022/3/7.
//

#include "Curve.h"

//#4 = DIRECTION ( 'NONE',  ( 1.000000000000000000, 0.0000000000000000000, 0.0000000000000000000 ) ) ;
Direction Direction::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("DIRECTION") == string::npos) {
        cout << "本条" + fileRow + "不是Direction，请检查文件格式";
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
    tempSplitVec[1] = tempSplitVec[1].substr(1, tempSplitVec[1].length());
    tempSplitVec[3] = tempSplitVec[3].substr(0, tempSplitVec[3].length() - 2);
    double x = stringToNum<double>(tempSplitVec[1]), y = stringToNum<double>(tempSplitVec[2]);
    double z = stringToNum<double>(tempSplitVec[3]);
    Direction direction(name, x, y, z);
    return direction;
}

//#22 = VECTOR ( 'NONE', #95, 1000.000000000000000 ) ;
Vector Vector::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("VECTOR") == string::npos) {
        cout << "本条" + fileRow + "不是Vector，请检查文件格式";
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
    tempSplitVec[2] = tempSplitVec[2].substr(0, tempSplitVec[2].length() - 1);
    Direction direction = Direction::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    double length = stringToNum<double>(tempSplitVec[2]);
    Vector vec(name, direction, length);
    return vec;
}

//#14 = LINE ( 'NONE', #28, #92 ) ;
Line Line::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("LINE") == string::npos) {
        cout << "本条" + fileRow + "不是Line，请检查文件格式";
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
    tempSplitVec[2] = tempSplitVec[2].substr(0, tempSplitVec[2].length() - 1);
    CartesianPoint cartesianPoint1 = CartesianPoint::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    Vector objectVector = Vector::handle(dataMap.find(tempSplitVec[2])->second, dataMap);
    Line line(name, cartesianPoint1, objectVector);
    return line;
}