//
// Created by Utkarsh Singh on 06-04-2024.
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
    cout<<"Rubik's Cube:\n\n";

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

vector<RubiksCube::MOVE> RubiksCube::randomCubeShuffle(unsigned int times) {
    vector<MOVE> moves_performed;
    srand(time(0));
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return moves_performed;
}

string RubiksCube::getCornerColourString(uint8_t ind) const {
    string str="";
    switch (ind) {
//        UFR
        case 0:
            str += getColourLetter(getColour(FACE::UP, 2, 2));
            str += getColourLetter(getColour(FACE::FRONT, 0, 2));
            str += getColourLetter(getColour(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColourLetter(getColour(FACE::UP, 2, 0));
            str += getColourLetter(getColour(FACE::FRONT, 0, 0));
            str += getColourLetter(getColour(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColourLetter(getColour(FACE::UP, 0, 0));
            str += getColourLetter(getColour(FACE::BACK, 0, 2));
            str += getColourLetter(getColour(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColourLetter(getColour(FACE::UP, 0, 2));
            str += getColourLetter(getColour(FACE::BACK, 0, 0));
            str += getColourLetter(getColour(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColourLetter(getColour(FACE::DOWN, 0, 2));
            str += getColourLetter(getColour(FACE::FRONT, 2, 2));
            str += getColourLetter(getColour(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColourLetter(getColour(FACE::DOWN, 0, 0));
            str += getColourLetter(getColour(FACE::FRONT, 2, 0));
            str += getColourLetter(getColour(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColourLetter(getColour(FACE::DOWN, 2, 2));
            str += getColourLetter(getColour(FACE::BACK, 2, 0));
            str += getColourLetter(getColour(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColourLetter(getColour(FACE::DOWN, 2, 0));
            str += getColourLetter(getColour(FACE::BACK, 2, 2));
            str += getColourLetter(getColour(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}

uint8_t RubiksCube::getCornerIndex(uint8_t ind) const
{
    string corner = getCornerColourString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColourString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}
