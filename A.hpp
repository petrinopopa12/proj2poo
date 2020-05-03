//
//  A.hpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#ifndef A_hpp
#define A_hpp

#include "Map.hpp"
#include "Agent.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

//Agentul A este cel mai puternic din punctul de vedere al //confruntarii in dueluri cu agentii de alt tip
//Insa agentul A se deplaseaza foarte incet pentru ca este mai masiv :)

class agent_A :public Agent {
public:
    agent_A(const Position &p) : Agent(p){}
    string get_agent_type()const{ return "A";}
    Position choose_new_position(const Map& map) const;
    //am incercat miscarea agentilor astfel incat sa nu se omoare //intre ei agentii de acelasi tip, insa nu a mers
    //Position choose_new_new_position(const Map& map) const;
};

#endif
