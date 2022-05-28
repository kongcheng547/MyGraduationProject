//
// Created by kongcheng547 on 2022/3/7.
//

#include "Point.h"

int CartesianPoint::num = 0;
//#28 = CARTESIAN_POINT ( 'NONE',  ( -60.54135500900765300, 39.41482248636472000, 0.0000000000000000000 ) )
CartesianPoint CartesianPoint::handle(string fileRow, map<string, string> dataMap) {
    if (fileRow.find("CARTESIAN_POINT") == string::npos) {
        cout << "本条" + fileRow + "不是笛卡尔点，请检查文件格式" << endl;
        getchar();
        exit(0);
    }
    if ((num <=10) || (num <= 100 && num % 10 == 0) || (num <= 1000 && num % 100 == 0) || (num >= 1000 && num % 1000 == 0)) {
        cout << "正在处理第" + to_string(num++) + "个笛卡尔点" << endl;
//        cout << "正在处理第" + to_string(num++) +"个笛卡尔点" << endl;
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
    tempSplitVec[3] = tempSplitVec[3].substr(0, tempSplitVec[3].length() - 2);
    double x = stringToNum<double>(tempSplitVec[1]), y = stringToNum<double>(tempSplitVec[2]);
    double z = stringToNum<double>(tempSplitVec[3]);
    CartesianPoint cartesianPoint(name, x, y, z);
    return cartesianPoint;
}

