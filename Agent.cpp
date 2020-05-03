//
//  Agent.cpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#include "Agent.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void Agent::set_position(const Position& new_position) {
    position.row = new_position.row;
    position.col = new_position.col;
}

Agent::Position Agent::get_position()const {
    return position;
}
