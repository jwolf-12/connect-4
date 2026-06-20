#include <bits/stdc++.h> 
using namespace std;

#include "position.hpp"
#include "solver.hpp"
#include <fstream>

int sign(int n){
    if(n>0) return 1;
    if(n==0) return 0;
    return -1;
}

int main() {
    ifstream fin("Test_L3_R1");

    int c=0;

    string moves;
    int expected_score;
    Solver s;
    while(fin >> moves >> expected_score){
        Position P;
        for(auto p :  moves){
            P.play(p-'1');
        }
        int score = s.negmax(P,-22,22);
        if(sign(score)==sign(expected_score)) c+=1;
    }
    cout << c/10.0 << endl;
}