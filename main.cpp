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

    Solver S;
    cout << P.nb_moves() << endl;
    cout << S.negmax(P) << endl;
}