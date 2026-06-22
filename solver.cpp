
#include "solver.hpp"
#include <bits/stdc++.h>
using namespace std;
#include <bitset>

Transportation_Table T(8388593);
static const int exploration_order[7] = {3,2,4,1,5,0,6};


int Solver::negmax(const Position& P,int alpha, int beta){

    explored_nodes++;

    if(P.nb_moves()==P.WIDTH*P.HEIGHT){ //draw state
        return 0;
    }

    for(int x : exploration_order){
        if(P.can_play(x) && P.is_winning_move(x)){
            return (P.WIDTH*P.HEIGHT +1 -P.nb_moves())/2;
        }
    }

    int max=(P.WIDTH*P.HEIGHT - P.nb_moves()-1)/2;
    if(int val = T.get(P.key())){
        max = val + P.MIN_SCORE -1;
    }

    if(beta>max){
        beta=max;
        if(alpha>=beta) return beta;
    }

    for(int x : exploration_order){
        if(P.can_play(x)){
            Position P2(P);
            P2.play(x);
            int score = -negmax(P2,-beta,-alpha);

            if(score>=beta) return score;
            if(score>alpha) alpha=score;
        }
    }
    T.put(P.key(),alpha - P.MIN_SCORE +1);
    return alpha;

}