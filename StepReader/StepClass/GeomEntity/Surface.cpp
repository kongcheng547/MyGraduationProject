//
// Created by kongcheng547 on 2022/3/7.
//

#include "Surface.h"

//#184 = AXIS2_PLACEMENT_3D ( 'NONE', #180, #146, #107 ) ;
Axis2Placement3D Axis2Placement3D::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("AXIS2_PLACEMENT_3D") == string::npos) {
        cout << "本条：" + fileRow + "不是AXIS2_PLACEMENT_3D，请检查文件格式" << endl;
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
    CartesianPoint locPoint = CartesianPoint::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    Direction normal = Direction::handle(dataMap.find(tempSplitVec[2])->second, dataMap);
    Direction referenceDir = Direction::handle(dataMap.find(tempSplitVec[3])->second, dataMap);
    return {name, locPoint, normal, referenceDir};
}

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
