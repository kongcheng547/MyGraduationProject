#include <iostream>
#include "string"
#include "math.h"
#include "ReadFile/StepFile.h"
#include "StepClass/SuperEntity.h"
#include "StepClass/GeomEntity/Point.h"
#include "StepClass/GeomEntity/ManifoldSolidBrep.h"
#include "StepClass/TopoEntity/ClosedShell.h"
#include "ctime"
#include "fstream"
using namespace std;

int main() {
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    string fileName = "man";
//    string filePath = "../src/car.STEP";
    string filePath = "../src/" + fileName + ".STEP";
//    string filePath = "../src/coupler.STEP";//扫描曲面surface_of_revolution待处理
    // chair的SURFACE_CURVE待处理
    StepFile stepFile;
    stepFile.readFile(filePath);
    stepFile.handleData();
    for (int i = 0; i < stepFile.manifoldString.size(); i++) {
        stepFile.manifoldSolidBrepVec.push_back(ManifoldSolidBrep::handle(
                stepFile.dataMap.find(stepFile.manifoldString[i])->second,stepFile.dataMap));
    }
    endTime = clock();
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    cout << "分钟是:" << (double)(endTime - startTime) / CLOCKS_PER_SEC / 60 << "min" << endl;

    ofstream outFile("../output/" + fileName + ".obj");
    for (int i = 0; i < stepFile.manifoldSolidBrepVec.size(); i++) {
        stepFile.manifoldSolidBrepVec[i].DrawToObj(outFile);
    }
    outFile.close();
    std::cout << "dada" << endl;
    return 0;
}