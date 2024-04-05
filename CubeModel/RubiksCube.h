//
// Created by utkarsh on 06-04-2024.
//

#ifndef RUBIKSCUBESOLVER_RUBIKSCUBE_H
#define RUBIKSCUBESOLVER_RUBIKSCUBE_H

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
};


#endif //RUBIKSCUBESOLVER_RUBIKSCUBE_H
