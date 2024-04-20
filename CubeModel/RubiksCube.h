//
// Created by Utkarsh Singh on 06-04-2024.
//

#ifndef RUBIKSCUBESOLVER_RUBIKSCUBE_H
#define RUBIKSCUBESOLVER_RUBIKSCUBE_H

#include <bits/stdc++.h>

using namespace std;

/* A base class for representation of all our Rubiks Cube Models.
 *Rubiks Cube can be modelled in several different representation with each of them
 *having its own special definitons. This class provides a shared functionality
 * between all models.
 * We'll benchmark all models and observe which one is better for performance.
*/

class RubiksCube {
    public:
        enum class FACE{
            UP,
            DOWN,
            LEFT,
            RIGHT,
            FRONT,
            BACK
        };

        enum class COLOUR{
            RED,BLUE,GREEN,WHITE,YELLOW,ORANGE
        };

        enum class MOVE{
            L,LPRIME,L2,
            R,RPRIME,R2,
            F,FPRIME,F2,
            D,DPRIME,D2,
            U,UPRIME,U2,
            B,BPRIME,B2
        };

        virtual COLOUR getColour(FACE face,unsigned row,unsigned col) const=0;

        static char getColourLetter(COLOUR colour);

        virtual bool isSolved() const=0;

        static string getMove(MOVE ind);

        /*
         *the cube is laid out as follows:
         * side wise:
         *      U
         *    L F R B
         *      D
         *
         *  colour wise:
         *
         *          W W W
         *          W W W
         *          W W W
         *
         *  G G G   R R R   B B B   O O O
         *  G G G   R R R   B B B   O O O
         *  G G G   R R R   B B B   O O O
         *
         *          Y Y Y
         *          Y Y Y
         *          Y Y Y
         *
         * Row and Column Numberings:
         * rx -> row numbering
         * cx -> column numbering
         * bx -> both row and column numbering
         *
         *             b0 c1 c2
         *             r1  .  .
         *             r2  .  .
         *
         *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
         *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
         *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
         *
         *             b0 c1 c2
         *             r1  .  .
         *             r2  .  .
         *
        */
        void print() const;

        vector<MOVE> randomCubeShuffle(unsigned int times);

        RubiksCube &move(MOVE ind);

        RubiksCube &invert(MOVE ind);

        virtual RubiksCube &f()=0;
        virtual RubiksCube &fPrime()=0;
        virtual RubiksCube &f2()=0;

        virtual RubiksCube &r()=0;
        virtual RubiksCube &rPrime()=0;
        virtual RubiksCube &r2()=0;

        virtual RubiksCube &b()=0;
        virtual RubiksCube &bPrime()=0;
        virtual RubiksCube &b2()=0;

        virtual RubiksCube &d()=0;
        virtual RubiksCube &dPrime()=0;
        virtual RubiksCube &d2()=0;

        virtual RubiksCube &l()=0;
        virtual RubiksCube &lPrime()=0;
        virtual RubiksCube &l2()=0;

        virtual RubiksCube &u()=0;
        virtual RubiksCube &uPrime()=0;
        virtual RubiksCube &u2()=0;

        string getCornerColourString(uint8_t ind) const;
        uint8_t getCornerIndex(uint8_t ind) const;
        uint8_t getCornerOrientation(uint8_t) const;
};


#endif //RUBIKSCUBESOLVER_RUBIKSCUBE_H
