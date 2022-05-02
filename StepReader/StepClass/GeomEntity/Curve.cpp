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

//B_SPLINE_CURVE ( 3, ( #712189, #349130, #657815, #587015 ),
//.UNSPECIFIED., .F., .F. )
BSplineCurve BSplineCurve::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("B_SPLINE_CURVE") == string::npos && fileRow.find('=') != string::npos) {
        cout << "本条" + fileRow + "不是B_SPLINE_CURVE，请检查文件格式" << endl;
        getchar();
        exit(0);
    }
    vector<string> tempSplitVec;
    Util util;
    util.split(fileRow, tempSplitVec, ',');
    string name = "";
    int degree;
    vector<CartesianPoint> controlPointsList;
    string curveForm;
    bool isClosedCurve, isSelfIntersect;
    int numLoc = 0;
    for (int i = tempSplitVec[0].length() - 1; tempSplitVec[0][i] >= '0' && tempSplitVec[0][i] <= '9' && i >= 0; i--) {
        numLoc = i;
    }
    degree = stringToNum<int>(tempSplitVec[0].substr(numLoc));
    for (int i = 1; i < tempSplitVec.size() - 3; i++) {
        string tempString = util.clearSelectedChar(tempSplitVec[i], '(');
        tempString = util.clearSelectedChar(tempString, ')');
        controlPointsList.push_back(CartesianPoint::handle(dataMap.find(tempString)->second, dataMap));
    }
    curveForm = tempSplitVec[tempSplitVec.size() - 3];
    isClosedCurve = tempSplitVec[tempSplitVec.size() - 2].find('F') == string::npos;
    isSelfIntersect = tempSplitVec[tempSplitVec.size() - 1].find('F') == string::npos;
    return {name, degree, controlPointsList, curveForm, isClosedCurve, isSelfIntersect};
}

//B_SPLINE_CURVE_WITH_KNOTS ( ( 4, 4 ),( 5.957302349958556675, 6.609068264400616677 ),.UNSPECIFIED. )
//#8667 = B_SPLINE_CURVE_WITH_KNOTS ( 'NONE', 3,
//( #52015, #752335, #310233, #673302, #43766, #114482, #560478, #181237, #168886, #423113 ),
//.UNSPECIFIED., .F., .F.,
//( 4, 2, 2, 2, 4 ),
//( 0.0000000000000000000, 0.2500000000000000000, 0.5000000000000000000, 0.7500000000000000000, 1.000000000000000000 ),
//.UNSPECIFIED. ) ;
BSplineCurveWithKnots BSplineCurveWithKnots::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find('=') != string::npos) {
        if (fileRow.find("B_SPLINE_CURVE_WITH_KNOTS") == string::npos) {
            cout << "本条" + fileRow + "不是B_SPLINE_CURVE_WITH_KNOTS，请检查文件格式" << endl;
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
        vector<vector<int>> bracketsVec = util.findBracketsVec(fileRow);
        // 去掉名字将后面属于BSplineSurface的部分字符串用其对应函数处理, 个数n需要结合字符串仔细想
        string temp = fileRow.substr(tempSplitVec[0].length() + 1,
                                     bracketsVec[bracketsVec.size() - 2][0] - tempSplitVec[0].length() - 2);
        BSplineCurve bSplineCurve = BSplineCurve::handle(temp, dataMap);
        bSplineCurve.name = name;
        vector<string> fileString;
        // 获得括号里面的字符串
        for (int i = 0; i < bracketsVec.size(); i++) {
            fileString.push_back(fileRow.substr(bracketsVec[i][0] + 1, bracketsVec[i][1] - 2));
        }
        vector<int> knotMultiplicities;
        vector<double> knots;
        string knotSpec;
        knotMultiplicities = util.handleIntString(fileString[fileString.size() - 2]);
        knots = util.handleDoubleString(fileString[fileString.size() - 1]);
        knotSpec = tempSplitVec[tempSplitVec.size() - 1];
        knotSpec = util.clearSelectedChar(knotSpec, ')');
        return {bSplineCurve, knotMultiplicities, knots, knotSpec};
    } else {
        if (fileRow.find("B_SPLINE_CURVE_WITH_KNOTS") == string::npos) {
            cout << "本条" + fileRow + "不是B_SPLINE_CURVE_WITH_KNOTS，请检查文件格式" << endl;
            getchar();
            exit(0);
        }
        vector<string> tempSplitVec;
        Util util;
        util.split(fileRow, tempSplitVec, ',');
        string name = "";
        vector<vector<int>> bracketsVec = util.findBracketsVec(fileRow);
        vector<string> fileString;
        // 获得括号里面的字符串
        for (int i = 0; i < bracketsVec.size(); i++) {
            fileString.push_back(fileRow.substr(bracketsVec[i][0] + 1, bracketsVec[i][1] - 2));
        }
        vector<int> knotMultiplicities = util.handleIntString(fileString[1]);
        vector<double> knots = util.handleDoubleString(fileString[2]);
        string knotSpec = util.clearSelectedChar(tempSplitVec[tempSplitVec.size() - 1], ')');
        return {name, knotMultiplicities, knots, knotSpec};
    }
}
//RATIONAL_B_SPLINE_CURVE ( ( 1.000000000000000000, 0.9649122807017562753, 0.9649122807017562753, 1.000000000000000000 ) )
RationalBSplineCurve RationalBSplineCurve::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("RATIONAL_B_SPLINE_CURVE") == string::npos) {
        cout << "本条" + fileRow + "不是RATIONAL_B_SPLINE_CURVE，请检查文件格式" << endl;
        getchar();
        exit(0);
    }
    vector<string> tempSplitVec;
    Util util;
//    util.split(fileRow, tempSplitVec, ',');
    string name = "";
    vector<vector<int>> bracketsVec = util.findBracketsVec(fileRow);
    vector<string> fileString;
    // 获得括号里面的字符串
    for (int i = 0; i < bracketsVec.size(); i++) {
        fileString.push_back(fileRow.substr(bracketsVec[i][0] + 1, bracketsVec[i][1] - 2));
    }
    vector<double> weightsData = util.handleDoubleString(fileString[1]);
    return {"", weightsData};
}

//#7921=(BOUNDED_CURVE()B_SPLINE_CURVE(3,(#712189,#349130,#657815,#587015),.UNSPECIFIED.,.F.,.F.)
//B_SPLINE_CURVE_WITH_KNOTS((4,4),(5.957302349958556675,6.609068264400616677),.UNSPECIFIED.)
//CURVE()GEOMETRIC_REPRESENTATION_ITEM()
//RATIONAL_B_SPLINE_CURVE((1.000000000000000000,0.9649122807017562753,0.9649122807017562753,1.000000000000000000))
//REPRESENTATION_ITEM(''));
BSplineCurveSet BSplineCurveSet::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("RATIONAL_B_SPLINE_CURVE") == string::npos && fileRow.find("B_SPLINE_CURVE") == string::npos
        && fileRow.find("B_SPLINE_CURVE_WITH_KNOTS") == string::npos) {
        cout << "本条" + fileRow + "不是BSplineCurveSet，请检查文件格式" << endl;
        getchar();
        exit(0);
    }
    Util util;
    vector<vector<int>> bracketsVec = util.findBracketsVec(fileRow);
    vector<string> fileString;
    // 获得括号里面的字符串
    for (int i = 0; i < bracketsVec.size(); i++) {
        fileString.push_back(fileRow.substr(bracketsVec[i][0], bracketsVec[i][1]));
    }
    int curveLoc = fileRow.find("B_SPLINE_CURVE"), knotsLoc = fileRow.find("B_SPLINE_CURVE_WITH_KNOTS");
    int rationalCurveLoc = fileRow.find("RATIONAL_B_SPLINE_CURVE");
    int curveIndex = 0, knotIndex = 0, rationalIndex = 0;
    for (int i = 0; i < bracketsVec.size() - 1; i++) {
        if (bracketsVec[i][0] < curveLoc && bracketsVec[i + 1][0] > curveLoc) {
            fileString[i + 1] = "B_SPLINE_CURVE" + fileString[i + 1];
            curveIndex = i + 1;
        }
        if (bracketsVec[i][0] < knotsLoc && bracketsVec[i + 1][0] > knotsLoc) {
            fileString[i + 1] = "B_SPLINE_CURVE_WITH_KNOTS" + fileString[i + 1];
            knotIndex = i + 1;
        }
        if (bracketsVec[i][0] < rationalCurveLoc && bracketsVec[i + 1][0] > rationalCurveLoc) {
            fileString[i + 1] = "RATIONAL_B_SPLINE_CURVE" + fileString[i + 1];
            rationalIndex = i + 1;
        }
    }
    if (curveIndex == 0 || knotIndex == 0 || rationalIndex == 0) {
        cout << fileRow + "未全部包含三个基础类型，请检查格式" << endl;
        getchar();
        exit(0);
    }
    string name = fileString[fileString.size() - 1] == "''" ? "" : fileString[fileString.size() - 1].substr(1, fileString[fileString.size() - 1].length() - 2);
    BSplineCurve bSplineCurve = BSplineCurve::handle(fileString[curveIndex], dataMap);
    BSplineCurveWithKnots bSplineCurveWithKnots = BSplineCurveWithKnots::handle(fileString[knotIndex], dataMap);
    RationalBSplineCurve rationalBSplineCurve = RationalBSplineCurve::handle(fileString[rationalIndex], dataMap);
    return {name, bSplineCurve, bSplineCurveWithKnots, rationalBSplineCurve};
}
