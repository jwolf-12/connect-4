#pragma once

#include<bits/stdc++.h>
using namespace std;
#include "position.hpp"

class Solver{
public:
    long long explored_nodes=0;

public:
    int negmax(const Position& P,int alpha,int beta);
};