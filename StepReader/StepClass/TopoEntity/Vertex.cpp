//
// Created by kongcheng547 on 2022/3/7.
//

#include "Vertex.h"

//#61 = VERTEX_POINT ( 'NONE', #174 ) ;
VertexPoint VertexPoint::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("VERTEX_POINT") == string::npos) {
        cout << "本条" + fileRow + "不是VERTEX_POINT，请检查文件格式" << endl;
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
    CartesianPoint locPoint = CartesianPoint::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    return {name, locPoint};
}
