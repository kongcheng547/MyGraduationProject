//
// Created by kongcheng547 on 2022/3/7.
//

#include "ClosedShell.h"

//#99 = CLOSED_SHELL ( 'NONE', ( #82, #177, #142, #147, #56, #161 ) ) ;
ClosedShell ClosedShell::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("CLOSED_SHELL") == string::npos) {
        cout << "本条" + fileRow + "不是CLOSED_SHELL，请检查文件格式" << endl;
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
    tempSplitVec[tempSplitVec.size() - 1] = tempSplitVec[tempSplitVec.size() - 1]
            .substr(0, tempSplitVec[tempSplitVec.size() - 1].length() - 2);
    vector<AdvancedFace> faceVector;
    for (int i = 1; i <= tempSplitVec.size() - 1; i++) {
        faceVector.push_back(AdvancedFace::handle(dataMap.find(tempSplitVec[i])->second, dataMap));
    }
    return {name, faceVector};
}
