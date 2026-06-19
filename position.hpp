#pragma once

#include <bits/stdc++.h>
using namespace std;
#include <cstdint>

class Position{
private:
    uint64_t position;
    uint64_t mask;
    int moves;

public:
    Position();
    bool can_play(int col) const;
    void play(int col);
    bool is_winning_move(int col) const;
    unsigned int nb_moves() const;
    void print();
    static const int WIDTH=7;
    static const int HEIGHT=6;

    static uint64_t top_mask(int col);
    static uint64_t bottom_mask(int col);
    static uint64_t column_mask(int col);

};
