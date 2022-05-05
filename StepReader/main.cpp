#include <iostream>
#include "string"
#include "ReadFile/StepFile.h"
#include "StepClass/SuperEntity.h"
#include "StepClass/GeomEntity/Point.h"
#include "StepClass/GeomEntity/ManifoldSolidBrep.h"
#include "StepClass/TopoEntity/ClosedShell.h"
#include "ctime"
using namespace std;

int main() {
    clock_t startTime,endTime;
    startTime = clock();//计时开始
//    string filePath = "../src/elevator.STEP";
    string filePath = "../src/cube.STEP";
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
    std::cout << "dada" << endl;
    return 0;
}