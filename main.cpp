#include "bits/stdc++.h"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "CubeModel/RubiksCube3dArray.cpp"
#include "CubeModel/RubiksCube1dArray.cpp"
#include "CubeModel/RubiksCubeBitboard.cpp"

using namespace std;

int main()
{
//    FOLLOWING CODE USED FOR TESTING PURPOSES.
//    !! MAKE SURE TO NOT UNCOMMENT MULTIPLE SECTIONS OF CODE COMMENTS AT THE SAME TIME
//    SEPARATED BY "--------" AS THEY MAY HAVE CONFLICTING VARIABLE NAMES!!


//    DFS-SOLVER----------------------------------------------------------------------------------------------------------------------------------------------


//    RubiksCube3dArray cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomCubeShuffle(3);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    DFSSolver<RubiksCube3dArray,int> DFSSolver(cube, 8);
//    vector<RubiksCube::MOVE> solve_moves = DFSSolver.solve();
//    //cout<<solve_moves.size()<<'\n';
//
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    DFSSolver.rubiksCube.print();


//    BFS-SOLVER----------------------------------------------------------------------------------------------------------------------------------------------


//    RubiksCube3dArray bit_cube;
//    bit_cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = bit_cube.randomCubeShuffle(6);
//    for (auto move: shuffle_moves) cout << bit_cube.getMove(move) << " ";
//    cout << "\n";
//    bit_cube.print();
//
//    BFSSolver<RubiksCube3dArray,Hash3d> bfsSolver(bit_cube);
//    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
//    for (auto move: solve_moves) cout << bit_cube.getMove(move) << " ";
//    cout<<'\n';
//    bfsSolver.rubiksCube.print();


//    IDDFS-SOLVER----------------------------------------------------------------------------------------------------------------------------------------------


//    RubiksCube1dArray bit_cube;
//    bit_cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = bit_cube.randomCubeShuffle(8);
//    for (auto move: shuffle_moves) cout << bit_cube.getMove(move) << " ";
//    cout << "\n";
//    bit_cube.print();
//
//    IDDFSSolver<RubiksCube1dArray,int> iddfsSolver(bit_cube);
//    vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
//    for (auto move: solve_moves) cout << bit_cube.getMove(move) << " ";
//    cout<<'\n';
//    iddfsSolver.rubiksCube.print();

//    RubiksCubeBitboard cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomCubeShuffle(8);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    IDDFSSolver<RubiksCubeBitboard,HashBitboard> iddfsSolver(cube);
//    vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout<<'\n';
//    iddfsSolver.rubiksCube.print();
}

