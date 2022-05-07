//
// Created by kongcheng547 on 2022/3/7.
//

#include "ManifoldSolidBrep.h"

//#3 = MANIFOLD_SOLID_BREP ( '凸台-拉伸1', #99 ) ;
ManifoldSolidBrep ManifoldSolidBrep::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("MANIFOLD_SOLID_BREP") == string::npos) {
        cout << "本条" + fileRow + "不是MANIFOLD_SOLID_BREP，请检查文件格式" << endl;
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
    tempSplitVec[1] = util.clearSelectedChar(tempSplitVec[1],')');
    ClosedShell closedShell = ClosedShell::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    return {name, closedShell};
}

void ManifoldSolidBrep::DrawToObj(ofstream &outFile) {
    this->closedShell.DrawToObj(outFile);
}
