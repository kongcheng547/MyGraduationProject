//
// Created by kongcheng547 on 2022/3/7.
//

#include "Face.h"

//#235202 = FACE_BOUND ( 'NONE', #750103, .T. ) ;
//#73 = FACE_OUTER_BOUND ( 'NONE', #188, .T. ) ;
FaceOuterBound FaceOuterBound::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("FACE_OUTER_BOUND") == string::npos && fileRow.find("FACE_BOUND") == string::npos) {
        cout << "本条" + fileRow + "不是FACE_OUTER_BOUND，请检查文件格式" << endl;
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
    tempSplitVec[2] = tempSplitVec[2][1];
    EdgeLoop edgeLoop = EdgeLoop::handle(dataMap.find(tempSplitVec[1])->second, dataMap);
    bool isTheSameDir = tempSplitVec[2] == "T";
    return {name, edgeLoop, isTheSameDir};
}

//#56 = ADVANCED_FACE ( 'NONE', ( #73 ), #101, .T. ) ;
AdvancedFace AdvancedFace::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("ADVANCED_FACE") == string::npos) {
        cout << "本条" + fileRow + "不是ADVANCED_FACE，请检查文件格式" << endl;
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
    tempSplitVec[1] = util.clearSelectedChar(tempSplitVec[1], '(');
    tempSplitVec[tempSplitVec.size() - 3] = util.clearSelectedChar(tempSplitVec[tempSplitVec.size() - 3], ')');
    vector<FaceOuterBound> boundVector;
    for (int i = 1; i <= tempSplitVec.size() - 3; i++) {
        boundVector.push_back(FaceOuterBound::handle(dataMap.find(tempSplitVec[i])->second, dataMap));
    }
    SurfacePointer surface = SurfacePointer::handle(dataMap.find(tempSplitVec[tempSplitVec.size() - 2])->second, dataMap);
    bool isTheSameDir = tempSplitVec[tempSplitVec.size() - 1].find('F') == string::npos;
    return {name, boundVector, surface, isTheSameDir};
}
