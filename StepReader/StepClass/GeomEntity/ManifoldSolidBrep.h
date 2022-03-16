//
// Created by kongcheng547 on 2022/3/7.
//

#ifndef STEPREADER_MANIFOLDSOLIDBREP_H
#define STEPREADER_MANIFOLDSOLIDBREP_H

#include "../SuperEntity.h"
#include "../TopoEntity/ClosedShell.h"

class ManifoldSolidBrep : public GeometricRepresentationItem {
public:
    ClosedShell closedShell;

    ManifoldSolidBrep(string name, ClosedShell closedShell1) : GeometricRepresentationItem(name),
                                                               closedShell(closedShell1) {}
};


#endif //STEPREADER_MANIFOLDSOLIDBREP_H
