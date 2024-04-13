//
// Created by utkarsh on 06-04-2024.
//

#include "RubiksCube.h"

char RubiksCube::getColourLetter(COLOUR colour) {
    switch (colour) {
        case COLOUR::BLUE:
            return 'B';
        case COLOUR::GREEN:
            return 'G';
        case COLOUR::RED:
            return 'R';
        case COLOUR::YELLOW:
            return 'Y';
        case COLOUR::WHITE:
            return 'W';
        case COLOUR::ORANGE:
            return 'O';
    }
}

string RubiksCube::getMove (MOVE ind){
   switch(ind)
   {
       case MOVE::L:
           return "L";
       case MOVE::LPRIME:
           return "L'";
       case MOVE::L2:
           return "L2";
       case MOVE::R:
           return "R";
       case MOVE::RPRIME:
           return "R'";
       case MOVE::R2:
           return "R2";
       case MOVE::U:
           return "U";
       case MOVE::UPRIME:
           return "U'";
       case MOVE::U2:
           return "U2";
       case MOVE::D:
           return "D";
       case MOVE::DPRIME:
           return "D'";
       case MOVE::D2:
           return "D2";
       case MOVE::F:
           return "F";
       case MOVE::FPRIME:
           return "F'";
       case MOVE::F2:
           return "F2";
       case MOVE::B:
           return "B";
       case MOVE::BPRIME:
           return "B'";
       case MOVE::B2:
           return "B2";
   }
}

RubiksCube &RubiksCube::move(RubiksCube::MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
    }
}

RubiksCube &RubiksCube::invert(RubiksCube::MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lPrime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}

void RubiksCube::print() const
{
    cout<<"Rubik's Cube:/n/n";

    for(int row=0;row<=2;row++)
    {
        for(unsigned i=0;i<7;i++)cout<<" ";
        for(int col=0;col<=2;col++) {
            cout << getColourLetter(getColour(FACE::UP, row, col)) << " ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int row=0;row<=2;row++)
    {
        for(int col=0;col<=2;col++) {
            cout << getColourLetter(getColour(FACE::LEFT, row, col)) << " ";
        }
        cout<<" ";
        for(int col=0;col<=2;col++) {
            cout << getColourLetter(getColour(FACE::FRONT, row, col)) << " ";
        }
        cout<<" ";
        for(int col=0;col<=2;col++) {
            cout << getColourLetter(getColour(FACE::RIGHT, row, col)) << " ";
        }
        cout<<" ";
        for(int col=0;col<=2;col++) {
            cout << getColourLetter(getColour(FACE::BACK, row, col)) << " ";
        }
        cout<<'\n';
    }

    cout<<'\n';
    for(int row=0;row<=2;row++){
        for(unsigned i=0;i<7;i++)cout<<" ";
        for(int col=0;col<=2;col++) {
            cout << getColourLetter(getColour(FACE::DOWN, row, col)) << " ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}


