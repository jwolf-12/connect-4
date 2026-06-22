#pragma once

#include <bits/stdc++.h>
using namespace std;
#include <cstdint>

class Transportation_Table{
    private:

    struct Entry{
        uint64_t key :56;
        uint8_t val;
    };

    vector<Entry> T;

    unsigned int index(uint64_t key) const{
        return key%T.size();
    }

public:
    Transportation_Table(unsigned int size){
        assert(size>0);
        T.resize(size+1);
    }

    void reset(){
        fill(T.begin(),T.end(),Entry{});
    }

    void put(uint64_t key,uint8_t val){
        assert(key < (1ULL << 56));
        unsigned int i = index(key);
        T[i].key=key; T[i].val=val; 
    }

    uint8_t get(uint64_t key) const {
        assert(key < (1ULL << 56));
        unsigned int i = index(key);
        if(T[i].key==key) return T[i].val;
        else return 0;
    }



};