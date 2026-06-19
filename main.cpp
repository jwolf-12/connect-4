#include <bits/stdc++.h> 
using namespace std;

#include "position.hpp"
#include "solver.hpp"

int main() {
    Position P;

    string moves = "2252576253462244111563365343671351441";

    for(char c : moves) {
        int col = c - '1';
        P.play(col);
        cout << "played" << endl;
    }

    for(int c=0;c<7;c++){
        cout << c << " "
            << P.can_play(c) << " "
            << P.is_winning_move(c)
            << endl;
    }
    P.print();

    Solver S;
    cout << P.nb_moves() << endl;
    cout << S.negmax(P,-1,1) << endl;
}