//
// Created by kongcheng547 on 2022/5/28.
//

#ifndef STEPREADER_DRAWUTIL_H
#define STEPREADER_DRAWUTIL_H
#include "../StepClass/SuperEntity.h"
#include "../StepClass/TopoEntity/Edge.h"
#include "math.h"

class DrawUtil {
public:
    vector<vector<double>> handleCircle(Circle *circle, int normNum);
    void crossMulti(double vec1[], double vec2[], double crossResult[]);
    void normVector(double vec[]);
    double sumOfSquares(double vec[]);
};


#endif //STEPREADER_DRAWUTIL_H
