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
    for (int i = 0; i < stepFile.manifoldString.size(); i++) {
        stepFile.manifoldSolidBrepVec.push_back(ManifoldSolidBrep::handle(
                stepFile.dataMap.find(stepFile.manifoldString[i])->second,stepFile.dataMap));
    }
//    ManifoldSolidBrep manifoldSolidBrep = ManifoldSolidBrep::handle(stepFile.dataMap.find("#3")->second, stepFile.dataMap);
    std::cout << "dada" << endl;
    return 0;
}