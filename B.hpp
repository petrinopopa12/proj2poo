//
//  B.hpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#ifndef B_hpp
#define B_hpp

#include <stdio.h>

#include "Map.hpp"
#include "Agent.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

//Agentul B este un agent mediu, are rezistenta in lupta doar in fata agentului C si se deplaseaza cu o viteza de 2 patratele/runda.


class agent_B :public Agent {
public:
    agent_B(const Position &p) : Agent(p){}
    string get_agent_type()const{ return "B";}
    Position choose_new_position(const Map& map) const;
    //Position choose_new_new_position(const Map& map) const;
};

#endif /* B_hpp */
