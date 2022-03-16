#include <iostream>
#include "string"
#include "ReadFile/StepFile.h"

using namespace std;
int main() {
    string filePath = "E:\\学习资料\\毕业设计\\step文件读取\\cube.STEP";
    StepFile stepFile;
    stepFile.readFile(filePath);
    stepFile.handleData();
    getchar();
    return 0;
}
