//
// Created by kongcheng547 on 2022/3/7.
//

#include "Curve.h"

//#14 = LINE ( 'NONE', #28, #92 ) ;
Line Line::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("LINE") == string::npos) {
        cout << "本条" + fileRow + "不是Line，请检查文件格式" << endl;
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

//#40 = CIRCLE ( 'NONE', #199555, 12.06499999999958028 ) ;
Circle Circle::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("CIRCLE") == string::npos) {
        cout << "本条" + fileRow + "不是Circle，请检查文件格式" << endl;
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
    Axis2Placement3D position = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    double radius = stringToNum<double>(tempSplitVec[2]);
    return {name, position, radius};
}

//#19973=ELLIPSE('',#534461,833.201531243235,498.5);
Ellipse Ellipse::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("ELLIPSE") == string::npos) {
        cout << "本条" + fileRow + "不是ELLIPSE，请检查文件格式" << endl;
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
    tempSplitVec[3] = tempSplitVec[3].substr(0, tempSplitVec[3].length() - 1);
    Axis2Placement3D position = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    double semiAxis1 = stringToNum<double>(tempSplitVec[2]);
    double semiAxis2 = stringToNum<double>(tempSplitVec[3]);
    return {name, position, semiAxis1, semiAxis2};
}

Hyperbola Hyperbola::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("HYPERBOLA") == string::npos) {
        cout << "本条" + fileRow + "不是HYPERBOLA，请检查文件格式" << endl;
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
    tempSplitVec[3] = tempSplitVec[3].substr(0, tempSplitVec[3].length() - 1);
    Axis2Placement3D position = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    double semiAxis = stringToNum<double>(tempSplitVec[2]);
    double semiImagAxis = stringToNum<double>(tempSplitVec[3]);
    return {name, position, semiAxis, semiImagAxis};
}

Parabola Parabola::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("PARABOLA") == string::npos) {
        cout << "本条" + fileRow + "不是Parabola，请检查文件格式" << endl;
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
    Axis2Placement3D position = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    double focalDist = stringToNum<double>(tempSplitVec[2]);
    return {name, position, focalDist};
}
