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
    util.split(fileRow, tempSplitVec, ','); // 以逗号分割
    regex re("[\\'](.*?)[\\']");
    smatch m;
    regex_search(tempSplitVec[0], m, re);   // 正则匹配两个引号之间的内容获得名称
    string name = m.str(0).substr(1, m.str(0).length() - 2);
    if (name == "NONE") {
        name = "";
    }
    // 因为分割出来第二个字符串含有括号，所以去掉括号字符串，取得干净的索引标号
    tempSplitVec[1] = util.clearSelectedChar(tempSplitVec[1],')');
    // 将获得的索引标号内容找到相关的dataMap中的value即对应行，然后调用对应类的handle函数返回对应对象
    ClosedShell closedShell = ClosedShell::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    // 获得manifold_solid_brep类所需要的数据成员closed_shell和名称后调用其构造函数返回一个对象
    return {name, closedShell};
}

void ManifoldSolidBrep::DrawToObj(ofstream &outFile) {
    this->closedShell.DrawToObj(outFile);
}
