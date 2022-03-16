#include <iostream>
#include "string"
#include "ReadFile/StepFile.h"
#include "StepClass/SuperEntity.h"
#include "StepClass/GeomEntity/Point.h"
#include "StepClass/GeomEntity/Surface.h"
using namespace std;

int main() {
    string filePath = "E:\\学习资料\\毕业设计\\step文件读取\\cube.STEP";
    StepFile stepFile;
    stepFile.readFile(filePath);
    stepFile.handleData();
    Plane plane = Plane::handle(stepFile.dataMap.find("#194")->second, stepFile.dataMap);
    return 0;
}
