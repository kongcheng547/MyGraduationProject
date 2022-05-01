cmake_minimum_required(VERSION 2.30)
project(StepReader)

set(CMAKE_CXX_STANDARD 14)

add_executable(StepReader main.cpp
        StepClass/SuperEntity.cpp StepClass/SuperEntity.h
        StepClass/GeomEntity/ManifoldSolidBrep.cpp StepClass/GeomEntity/ManifoldSolidBrep.h
        StepClass/GeomEntity/Point.cpp StepClass/GeomEntity/Point.h StepClass/GeomEntity/Curve.cpp
        StepClass/GeomEntity/Curve.h StepClass/GeomEntity/Surface.cpp StepClass/GeomEntity/Surface.h
        StepClass/TopoEntity/Vertex.cpp StepClass/TopoEntity/Vertex.h StepClass/TopoEntity/Edge.cpp
        StepClass/TopoEntity/Edge.h StepClass/TopoEntity/Loop.cpp StepClass/TopoEntity/Loop.h
        StepClass/TopoEntity/Face.cpp StepClass/TopoEntity/Face.h StepClass/TopoEntity/ClosedShell.cpp
        StepClass/TopoEntity/ClosedShell.h ReadFile/FileReader.cpp ReadFile/FileReader.h ReadFile/StepFile.cpp
        ReadFile/StepFile.h Util/Util.cpp Util/Util.h StepClass/GeomEntity/MiddleGeom.cpp StepClass/GeomEntity/MiddleGeom.h)
