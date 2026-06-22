#pragma once

#include<bits/stdc++.h>
using namespace std;
#include "position.hpp"
#include "transportation_table.hpp"

class Solver{
public:
    long long explored_nodes=0;

public:
    int negmax(const Position& P,int alpha,int beta);

    int solve(const Position &P, bool weak = false) 
        {
        int min = P.MIN_SCORE;
        int max = P.MAX_SCORE;
        if(weak) {
            min = -1;
            max = 1;
        }
        while(min < max) {                    
            int med = min + (max - min)/2;
            int r = negmax(P, med, med + 1); 
            if(r <= med) max = r;
            else min = r;
        }
        return min;
        }
};