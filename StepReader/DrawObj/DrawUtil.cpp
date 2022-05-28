//
// Created by kongcheng547 on 2022/5/28.
//

#include "DrawUtil.h"

vector<vector<double>> DrawUtil::handleCircle(Circle *circle, int normNum) {
    vector<vector<double>> circlePoint;
    double normal[] = {circle->position.normal.x, circle->position.normal.y, circle->position.normal.z};
    for (int i = 0; i < 3; i++) {
        normal[i] *= normNum;
    }
    double x[] = {1, 0, 0}, y[] = {0, 1, 0};
    double a[3];
    crossMulti(normal, x, a);
    if (sumOfSquares(a) == 0) {
        crossMulti(normal, y, a);
    }
    double b[3];
    crossMulti(normal, a, b);
    normVector(a);
    normVector(b);
    double PI = 3.14159265 * 2;
    double radius = circle->radius;
    vector<double> center = {circle->position.locPoint.x, circle->position.locPoint.y, circle->position.locPoint.z};
    circlePoint.push_back(center);
    for (int i = 0; i < 100; i++) {
        double cosAng = cos(PI * i / 100);
        double sinAng = sin(PI * i / 100);
        vector<double> tempVec;
        tempVec.push_back(center[0] + radius * a[0] * cosAng + radius * b[0] * sinAng);
        tempVec.push_back(center[1] + radius * a[1] * cosAng + radius * b[1] * sinAng);
        tempVec.push_back(center[2] + radius * a[2] * cosAng + radius * b[2] * sinAng);
        circlePoint.push_back(tempVec);
    }
    return circlePoint;
}

// 叉乘
void DrawUtil::crossMulti(double *vec1, double *vec2, double *crossResult) {
    crossResult[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    crossResult[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    crossResult[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
}

// 单位化向量
void DrawUtil::normVector(double *vec) {
    double multi = sumOfSquares(vec);
    vec[0] = vec[0] / multi;
    vec[1] = vec[1] / multi;
    vec[2] = vec[2] / multi;
}

double DrawUtil::sumOfSquares(double *vec) {
    return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}
