//
//  Agent.hpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#ifndef Agent_hpp
#define Agent_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Map;

class Agent {
public:
    struct Position {
    int row;
    int col;
    Position(const int r, const int c) {
        row = r;
        col = c;
    }
    bool operator==(const Position &p) {
        if(p.row==row && p.col==col)
            return true;
        return false;
    }
    };
protected:
        void set_position(const Position& new_position);
        struct Position position;
public:
    Agent(Position p) : position(p) {};
    virtual ~Agent() {};
    Position get_position() const;
    virtual string get_agent_type() const =0;
    virtual Position choose_new_position(const Map& map) const =0;
    //virtual Position choose_new_new_position(const Map& map) const =0;
    friend class Map;

};

#endif
