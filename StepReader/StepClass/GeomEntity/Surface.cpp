//
// Created by kongcheng547 on 2022/3/7.
//

#include "Surface.h"

//#194 = PLANE ( 'NONE',  #184 ) ;
Plane Plane::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("PLANE") == string::npos) {
        cout << "本条" + fileRow + "不是Plane，请检查文件格式" << endl;
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
    tempSplitVec[1] = tempSplitVec[1].substr(0, tempSplitVec[1].length() - 1);
    Axis2Placement3D axis2Placement3D = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    return {name, axis2Placement3D};
}

//#72349=CYLINDRICAL_SURFACE('',#534452,32.5);
CylindricalSurface CylindricalSurface::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("CYLINDRICAL_SURFACE") == string::npos) {
        cout << "本条" + fileRow + "不是CYLINDRICAL_SURFACE，请检查文件格式" << endl;
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
    Axis2Placement3D axis2Placement3D = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    double radius = util.DoubleStringHandle(tempSplitVec[2]);
    return {name, axis2Placement3D, radius};
}

//#75476=CONICAL_SURFACE('',#534384,2.,0.785398163397335);
ConicalSurface ConicalSurface::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("CONICAL_SURFACE") == string::npos) {
        cout << "本条" + fileRow + "不是CONICAL_SURFACE，请检查文件格式" << endl;
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
    double radius = util.DoubleStringHandle(tempSplitVec[2]);
    double semiAngle = util.DoubleStringHandle(tempSplitVec[3]);
    Axis2Placement3D axis2Placement3D = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    return {name, axis2Placement3D, radius, semiAngle};
}

//#1704=SPHERICAL_SURFACE('',#534984,17.5);
SphericalSurface SphericalSurface::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("SPHERICAL_SURFACE") == string::npos) {
        cout << "本条" + fileRow + "不是SPHERICAL_SURFACE，请检查文件格式" << endl;
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
    double radius = util.DoubleStringHandle(tempSplitVec[2]);
    Axis2Placement3D axis2Placement3D = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    return {name, axis2Placement3D, radius};
}

//#500841=TOROIDAL_SURFACE('',#534377,48.6859195925902,0.1);
ToroidalSurface ToroidalSurface::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("TOROIDAL_SURFACE") == string::npos) {
        cout << "本条" + fileRow + "不是TOROIDAL_SURFACE，请检查文件格式" << endl;
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
    double majorRadius = util.DoubleStringHandle(tempSplitVec[2]);
    double minorRadius = util.DoubleStringHandle(tempSplitVec[3]);
    Axis2Placement3D axis2Placement3D = Axis2Placement3D::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    return {name, axis2Placement3D, majorRadius, minorRadius};
}

//B_SPLINE_SURFACE ( 3, 3, (
// ( #677656, #102488, #35859, #806955 ),
// ( #602794, #477782, #235740, #173264 ),
// ( #759822, #798782, #481853, #165031 ),
// ( #611046, #427523, #126083, #521818 ) ),
// .UNSPECIFIED., .F., .F., .F. )
BSplineSurface BSplineSurface::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("B_SPLINE_SURFACE") == string::npos) {
        cout << "本条" + fileRow + "不是B_SPLINE_SURFACE，请检查文件格式" << endl;
        getchar();
        exit(0);
    }
    vector<string> tempSplitVec;
    Util util;
    util.split(fileRow, tempSplitVec, ',');
    string name = "";
    int numLoc = 0;
    for (int i = tempSplitVec[0].length() - 1; tempSplitVec[0][i] >= '0' && tempSplitVec[0][i] <= '9' && i >= 0; i--) {
        numLoc = i;
    }
    int u_degree = stringToNum<int>(tempSplitVec[0].substr(numLoc, tempSplitVec[0].length()));
    int v_degree = stringToNum<int>(tempSplitVec[1]);
    vector<vector<CartesianPoint>> controlPointsList;
    string surfaceForm = tempSplitVec[tempSplitVec.size() - 4];
    bool u_closed = tempSplitVec[tempSplitVec.size() - 3].find('F') == string::npos;
    bool v_closed = tempSplitVec[tempSplitVec.size() - 2].find('F') == string::npos;
    bool selfIntersect = tempSplitVec[tempSplitVec.size() - 1].find('F') == string::npos;
    for (int i = 2; i < tempSplitVec.size() - 4;) {
        vector<CartesianPoint> ctlPointList;
        while (true) {
            if (tempSplitVec[i].find(')') != string::npos) {
                string tempString = util.clearSelectedChar(tempSplitVec[i], ')');
                tempString = util.clearSelectedChar(tempString, '(');
                ctlPointList.push_back(CartesianPoint::handle(dataMap.find(tempString)->second, dataMap));
                i++;
                controlPointsList.push_back(ctlPointList);
                break;
            }
            string tempString = util.clearSelectedChar(tempSplitVec[i], '(');
            ctlPointList.push_back(CartesianPoint::handle(dataMap.find(tempString)->second, dataMap));
            i++;
        }
    }
    return {name, u_degree, v_degree, controlPointsList, surfaceForm, u_closed, v_closed, selfIntersect};
}

//B_SPLINE_SURFACE_WITH_KNOTS ( ( 4, 4 ),
//( 4, 4 ),
//( 0.0000000000000000000, 1.000000000000000000 ),
//( 0.0000000000000000000, 1.000000000000000000 ),
//.UNSPECIFIED. )
BSplineSurfaceWithKnots BSplineSurfaceWithKnots::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("B_SPLINE_SURFACE_WITH_KNOTS") == string::npos) {
        cout << "本条" + fileRow + "不是B_SPLINE_SURFACE_WITH_KNOTS，请检查文件格式" << endl;
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
    vector<int> u_multiplicities = util.handleIntString(fileString[1]);
    vector<int> v_multiplicities = util.handleIntString(fileString[2]);
    vector<double> u_knots = util.handleDoubleString(fileString[3]);
    vector<double> v_knots = util.handleDoubleString(fileString[4]);
    string knot_spec = tempSplitVec[tempSplitVec.size() - 1];
    return {name, u_multiplicities, v_multiplicities, u_knots, v_knots, knot_spec};
}
