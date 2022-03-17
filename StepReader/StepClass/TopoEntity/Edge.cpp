//
// Created by kongcheng547 on 2022/3/7.
//

#include "Edge.h"

//#157 = EDGE_CURVE ( 'NONE', #118, #66, #47, .T. ) ;
EdgeCurve EdgeCurve::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("EDGE_CURVE") == string::npos) {
        cout << "本条" + fileRow + "不是EDGE_CURVE，请检查文件格式" << endl;
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
    tempSplitVec[4] = tempSplitVec[4][1];
    VertexPoint startPoint = VertexPoint::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    VertexPoint endPoint = VertexPoint::handle(dataMap.find(tempSplitVec[2])->second, dataMap);
    Line curve = Line::handle(dataMap.find(tempSplitVec[3])->second, dataMap);
    bool isTheSameDir = tempSplitVec[4] == "T";
    return {name, startPoint, endPoint, curve, isTheSameDir};
}

//#159 = ORIENTED_EDGE ( 'NONE', *, *, #175, .F. ) ;
// TODO: 目前暂时当做是只有一个edge_curve组成 后续需要更改
OrientedEdge OrientedEdge::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("ORIENTED_EDGE") == string::npos) {
        cout << "本条" + fileRow + "不是ORIENTED_EDGE，请检查文件格式" << endl;
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
    tempSplitVec[4] = tempSplitVec[4][1];
    EdgeCurve edgeCurve = EdgeCurve::handle(dataMap.find(tempSplitVec[3])->second, dataMap);
    bool isTheSameDir = tempSplitVec[4] == "T";
    return {name, edgeCurve, isTheSameDir};
}
