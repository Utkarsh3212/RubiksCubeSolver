cmake_minimum_required(VERSION 3.27)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp
        CubeModel/RubiksCube.cpp
        CubeModel/RubiksCube.h
        CubeModel/RubiksCube3dArray.cpp
        CubeModel/RubiksCube1dArray.cpp
        CubeModel/RubiksCubeBitboard.cpp
        Solver/BFSSolver.h
        Solver/DFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h)
