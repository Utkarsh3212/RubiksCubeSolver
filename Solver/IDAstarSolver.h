//
// Created by Utkarsh Singh on 4/19/24.
//
#include "bits/stdc++.h"
#include "../CubeModel/RubiksCube.h"

#ifndef RUBIKS_CUBE_DFS_SOLVER_H
#define RUBIKS_CUBE_DFS_SOLVER_H

template<typename T,typename H>
class IDAstarSolver{
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<T,bool,H> visited;
    unordered_map<T,RubiksCube::MOVE,H> move_done;

    int estimator(T cube){return 0;}

    struct Node{
        T cube;
        int depth;
        int estimate;
        Node(T _cube,int _depth,int _estimate){
            cube=_cube;
            depth=_depth;
            estimate=_estimate;
        }
    };

    struct compareCube{
        bool operator()(pair<Node,int> const &p1,pair<Node,int> const &p2)
        {
            auto u1=p1.first,u2=p2.first;
            if(u1.depth+u1.estimate==u2.estimate+u2.depth)
            {
                return u1.estimate>u2.estimate;
            }
            else return (u1.depth+u1.estimate>u2.estimate+u2.depth);
        }
    };

    void restructure()
    {
        visited.clear();
        moves.clear();
        move_done.clear();
    }

//  Returns {solved_cube node,bound} if it finds a goal state, else returns {rubiksCube node,next_bound}.
    pair<T,int> IDAstar(int bound)
    {
//      priority queue stores the current node and the value of previous move performed.
        priority_queue<pair<Node,int>,vector<pair<Node,int>>,compareCube> pq;
        Node start= Node(rubiksCube,0,estimator(rubiksCube));
        pq.push(make_pair(start,0));
        int next_bound=10000;
        while(!pq.empty())
        {
            auto curr=pq.top();
            T curr_cube=curr.first.cube;
            Node curr_node=curr.first;
            pq.pop();
            if(visited[curr_cube]) continue;
            visited[curr_cube]=true;
            move_done[curr_cube]=curr.second;
            if(curr_cube.isSolved())return {curr_cube,bound};
            curr_node.depth++;
            for(int i=0;i<18;i++){
                curr_cube.move(RubiksCube::MOVE(i));
                if(!visited[curr_cube])
                {
                    curr_node.estimate=estimator(curr_cube);
                    if(curr_node.depth+curr_node.estimate>bound)
                    {
                        next_bound=min(next_bound,curr_node.depth+curr_node.estimate);
                    }else{
                        pq.push(make_pair(curr_node,i));
                    }
                }
                curr_cube.invert(RubiksCube::MOVE(i));
            }
        }
        return make_pair(rubiksCube,next_bound);
    }

public:
    T rubiksCube;

    IDAstarSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    vector<RubiksCube::MOVE> solve()
    {
        int bound=1;
        auto x = IDAstar(bound);
        while(x.second!=bound)
        {
            restructure();
            x=IDAstar(x.second);
            bound=x.second;
        }
        T solved_cube=x.first;
        assert(solved_cube.isSolved());
        T curr_cube=solved_cube;
        while(!(curr_cube==rubiksCube))
        {
            moves.push_back(move_done[curr_cube]);
            curr_cube.invert(move_done[curr_cube]);
        }
        rubiksCube=solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif