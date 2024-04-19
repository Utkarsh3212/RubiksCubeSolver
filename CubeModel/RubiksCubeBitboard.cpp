//
// Created by Utkarsh Singh on 4/19/24.
//
#include "RubiksCube.h"

class RubiksCubeBitboard{
private:
    uint64_t solved_side_config[6];
    int arr[3][3]={{0,1,2},
                   {7,8,3},
                   {6,5,4}};

    uint64_t one_8=(1<<8)-1,one_24=(1<<24)-1;

    void RotateFace(int ind) {
        uint64_t side=bitboard[ind];
        side=side>>48;
        bitboard[ind]=(bitboard[ind]<<16) | side;
    }

    void rotateSide(int s1, int s1_1, int s1_2,int s1_3,int s2, int s2_1, int s2_2,int s2_3)
    {
        uint64_t clr1 = (bitboard[s2] & (one_8 << (8 * s2_1))) >> (8 * s2_1);
        uint64_t clr2 = (bitboard[s2] & (one_8 << (8 * s2_2))) >> (8 * s2_2);
        uint64_t clr3 = (bitboard[s2] & (one_8 << (8 * s2_3))) >> (8 * s2_3);

        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_1))) | (clr1 << (8 * s1_1));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_2))) | (clr2 << (8 * s1_2));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_3))) | (clr3 << (8 * s1_3));
    }

    int get5bitCorner(string corner) {
        int ret = 0;
        string actual_str;
        for (auto c: corner) {
            if (c != 'W' && c != 'Y') continue;
            actual_str.push_back(c);
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

        if (corner[1] == actual_str[0]) {
            ret |= (1 << 3);
        } else if (corner[2] == actual_str[0]) {
            ret |= (1 << 4);
        }
        return ret;
    }

public:
    uint64_t bitboard[6];

    RubiksCubeBitboard()
    {
        for(int side=0;side<6;side++){
            uint64_t clr=1<<side;
            bitboard[side]=0;
            for(int faceIdx=0;faceIdx<8;faceIdx++){
                bitboard[side] |= clr<<(8*side);
            }
            solved_side_config[side]=bitboard[side];
        }
    }
};