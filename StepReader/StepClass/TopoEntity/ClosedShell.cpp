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
    // 正则表达式匹配名称
    string name = m.str(0).substr(1, m.str(0).length() - 2);
    if (name == "NONE") {
        name = "";
    }
    // 第一项含有一个左括号，去掉左括号
    tempSplitVec[1] = tempSplitVec[1].substr(1, tempSplitVec[1].length());
    // 最后一项有一个右括号，去掉右括号
    tempSplitVec[tempSplitVec.size() - 1] = tempSplitVec[tempSplitVec.size() - 1]
            .substr(0, tempSplitVec[tempSplitVec.size() - 1].length() - 2);
    vector<AdvancedFace> faceVector;
    // 将获得的纯净的高级面的索引号用来调用高级面的handle()函数，获得高级面对象，并存入vector
    for (int i = 1; i <= tempSplitVec.size() - 1; i++) {
        faceVector.push_back(AdvancedFace::handle(dataMap.find(tempSplitVec[i])->second, dataMap));
    }
    return {name, faceVector};
}

void ClosedShell::DrawToObj(ofstream &outFile) {
    for (int i = 0; i < this->faceVector.size(); i++) {
        this->faceVector[i].DrawToObj(outFile);
    }
}
