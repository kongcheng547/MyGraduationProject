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
    string filePath = "../src/cube.STEP";
    StepFile stepFile;
    stepFile.readFile(filePath);
    stepFile.handleData();
    ManifoldSolidBrep manifoldSolidBrep = ManifoldSolidBrep::handle(stepFile.dataMap.find("#3")->second, stepFile.dataMap);
    std::cout << "dada" << endl;
    return 0;
}


//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <iostream>
//
//void render()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_TRIANGLES);
//    glVertex3f(-0.5f, -0.5f, 0.0f);
//    glVertex3f(0.5f, 0.0f, 0.0f);
//    glVertex3f(0.0f, 0.5f, 0.0f);
//    glEnd();
//    glFlush();
//}
//
//int main(int argc, char* argv[]) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(480, 320);
//    glutInitWindowPosition(200, 100);
//    glutCreateWindow("OpenGL Window Test");
//
//    glutDisplayFunc(render);
//
//    glutMainLoop();
//    return 0;
//}