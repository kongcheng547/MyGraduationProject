#include <iostream>
#include "string"
#include "ReadFile/StepFile.h"
#include "StepClass/SuperEntity.h"
#include "StepClass/GeomEntity/Point.h"
#include "StepClass/GeomEntity/ManifoldSolidBrep.h"
#include "StepClass/TopoEntity/ClosedShell.h"
using namespace std;

int main() {
//    string filePath = "E:\\学习资料\\毕业设计\\MyGraduationProject\\step文件夹\\cube.STEP";
    string filePath = "../src/elevator.STEP";
//    string filePath = "../src/cube.STEP";
    StepFile stepFile;
    stepFile.readFile(filePath);
    stepFile.handleData();
    string fileRow = "#13249=B_SPLINE_CURVE_WITH_KNOTS('NONE',3,(#179795,#434035,#692414,#563130),.UNSPECIFIED.,.F.,.F.,(4,4),(2.084290159931237583E-07,0.0008963801489708131225),.UNSPECIFIED.);";
//    string fileRow = "#13845=(BOUNDED_CURVE()B_SPLINE_CURVE(3,(#261587,#195121,#441108,#449324),.UNSPECIFIED.,.F.,.F.)B_SPLINE_CURVE_WITH_KNOTS((4,4),(3.141592653589696305,3.926990816986777322),.UNSPECIFIED.)CURVE()GEOMETRIC_REPRESENTATION_ITEM()RATIONAL_B_SPLINE_CURVE((1.000000000000000000,0.9492530216742380844,0.9492530216742380844,1.000000000000000000))REPRESENTATION_ITEM(''))";
//    for (int i = 0; i < stepFile.manifoldString.size(); i++) {
//        stepFile.manifoldSolidBrepVec.push_back(ManifoldSolidBrep::handle(
//                stepFile.dataMap.find(stepFile.manifoldString[i])->second,stepFile.dataMap));
//    }
//    ManifoldSolidBrep manifoldSolidBrep = ManifoldSolidBrep::handle(stepFile.dataMap.find("#3")->second, stepFile.dataMap);
    BSplineCurveWithKnots rationalBSplineSurface = BSplineCurveWithKnots::handle(fileRow, stepFile.dataMap);
    std::cout << "dada" << endl;
    return 0;
}
//#include <iostream>
//using namespace std;
//class B
//{
//public:
//    int len = 2;
//    B* b;
//    void B1(void)
//    {
//        B2();
//    }
//
//    virtual void B2(void)
//    {
//        cout << "Hello, B2" << endl;
//    }
//
//};
//
//class A:public B
//{
//public:
//    int len = 10;
//    virtual void B2(void)
//    {
//        cout << "Hello, A" << endl;
//    }
//    void B3(void) {
//        cout << "测试" << endl;
//    }
//
//};
//
//int main()
//{
////    B *pA=new A;
////    pA->b = new A;
////    if (pA->len == 2) {
////        A *a = dynamic_cast<A*>(pA->b);
////        cout << a->len <<endl;
////    }
//////    pA->B1();
//////    cout << pA->b->len << endl;
//////    cout << "Hello, world!" << endl;
////    return 0;
//
//    string fileRow = " B_SPLINE_SURFACE_WITH_KNOTS ( ( 4, 4 ),( 4, 4 ),( 0.0000000000003000000, 1.0006900000000000000 ),( 0.0000000000000000000, 1.000000000000000000 ),.UNSPECIFIED. ) ";
////    if (fileRow.find("B_SPLINE_SURFACE") == string::npos) {
////        cout << "本条" + fileRow + "不是B_SPLINE_SURFACE，请检查文件格式" << endl;
////        getchar();
////        exit(0);
////    }
//    vector<string> tempSplitVec;
//    Util util;
//    fileRow = util.clearSelectedChar(fileRow, '\n');
//    fileRow = util.clearSelectedChar(fileRow, ' ');
//    util.split(fileRow, tempSplitVec, ',');
//    string name = "";
//    vector<vector<int>> bracketsMatch = util.findBracketsVec(fileRow);
//    vector<string> fileString;
//    for (int i = 0; i < bracketsMatch.size(); i++) {
//        fileString.push_back(fileRow.substr(bracketsMatch[i][0] + 1, bracketsMatch[i][1] - 2));
//    }
//    vector<int> uu = util.handleIntString(fileString[1]);
//    vector<double> vv = util.handleDoubleString(fileString[3]);
////    int numLoc = 0;
////    for (int i = tempSplitVec[0].length() - 1; tempSplitVec[0][i] >= '0' && tempSplitVec[0][i] <= '9' && i >= 0; i-- ) {
////        numLoc = i;
////    }
////    int u_degree = stringToNum<int>(tempSplitVec[0].substr(numLoc, tempSplitVec[0].length()));
////    int v_degree = stringToNum<int>(tempSplitVec[1]);
////    vector<vector<string>> controlPointsList;
////    string surfaceForm = tempSplitVec[tempSplitVec.size() - 4];
////    bool u_closed = tempSplitVec[tempSplitVec.size() - 3].find('F') == string::npos;
////    bool v_closed = tempSplitVec[tempSplitVec.size() - 2].find('F') == string::npos;
////    bool selfIntersect = tempSplitVec[tempSplitVec.size() - 1].find('F') == string::npos;
////    for (int i = 2; i < tempSplitVec.size() - 4;) {
////        vector<string> ctlPointList;
////        while (true) {
////            if (tempSplitVec[i].find(')') != string::npos) {
////                string tempString = util.clearSelectedChar(tempSplitVec[i], ')');
////                tempString = util.clearSelectedChar(tempString, '(');
////                ctlPointList.push_back(tempString);
////                i++;
////                controlPointsList.push_back(ctlPointList);
////                break;
////            }
////            string tempString = util.clearSelectedChar(tempSplitVec[i], '(');
////            ctlPointList.push_back(tempString);
////            i++;
////        }
////    }
////    cout << "dada" << endl;
//    return 0;
//}