#include "position.hpp"
#include <bitset>

Position::Position(){
    position=0;
    mask=0;
    moves=0;
}

uint64_t Position::top_mask(int col){
    return 1ULL << (col*7 +5);
}

bool Position::can_play(int col) const{
    return (mask & top_mask(col))==0;
}

void Position::print(){
    cout << bitset<49>(position) << endl;
    cout << bitset<49>(mask) << endl;
}

uint64_t Position::bottom_mask(int col){
    return 1ULL << (col*7);
}

void Position::play(int col){
    position=position^mask;
    mask |= (mask + bottom_mask(col));
    moves+=1;
}

uint64_t Position::column_mask(int col){
    return ((1ULL << 7) -1) << (col*7);
}

bool Position::is_winning_move(int col) const {
    uint64_t pos = position |
                   ((mask + bottom_mask(col)) & column_mask(col));

    uint64_t m;

    // horizontal
    m = pos & (pos >> (HEIGHT+1));
    if(m & (m >> (2*(HEIGHT+1)))) return true;

    // diagonal /
    m = pos & (pos >> HEIGHT);
    if(m & (m >> (2*HEIGHT))) return true;

    // diagonal 
    m = pos & (pos >> 8);
    if(m & (m >> 16)) return true;

    // vertical
    m = pos & (pos >> 1);
    if(m & (m >> 2)) return true;

    return false;
}

unsigned int Position::nb_moves() const{
    return moves;
}