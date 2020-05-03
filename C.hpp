//
//  C.hpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#ifndef C_hpp
#define C_hpp

#include <stdio.h>

#include "Map.hpp"
#include "Agent.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

// Agentul C este cel mai vulnerabil in fata duelurilor, insa recupereaza prin faptul ca este capabil sa se miste cel mai rapid dintre toti agentii, reusit sa scape de multe ori de confruntari.


class agent_C :public Agent {
public:
    agent_C(const Position &p) : Agent(p){}
    string get_agent_type()const{ return "C";}
    Position choose_new_position(const Map& map) const;
    //Position choose_new_new_position(const Map& map) const;
};

#endif /* C_hpp */
