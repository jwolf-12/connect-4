
#include "solver.hpp"
#include <bits/stdc++.h>
using namespace std;
#include <bitset>

int Solver::negmax(const Position& P){
    if(P.nb_moves()==P.WIDTH*P.HEIGHT){ //draw state
        return 0;
    }

    for(int x=0;x<P.WIDTH;x++){
        if(P.can_play(x) && P.is_winning_move(x)){
            return (P.WIDTH*P.HEIGHT +1 -P.nb_moves())/2;
        }
    }

    int best_score=P.WIDTH*P.HEIGHT*-1;

    for(int x=0;x<P.WIDTH;x++){
        if(P.can_play(x)){
            Position P2(P);
            P2.play(x);
            best_score=max(best_score,negmax(P2)*-1);
        }
    }
    return best_score;

}