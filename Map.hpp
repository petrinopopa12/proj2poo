//
//  Map.hpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include "Agent.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Map {
    const int rowsNo;
    const int colNo;
    Agent ***agents_matrix;
    vector<Agent*>  agents;
    
public:
    //construiesc harta
    Map(const int row, const int col);
    //destructor
    virtual ~Map();
    
    void add_agent(const Agent* agent, const int row, const int col);
    void remove_agent(const Agent* agent);
    vector<Agent*> get_all_agents() const;
    Agent* get_agent_position(const int row, const int col) const;
    void move_agent(Agent* const agent, const int new_row, const int new_col);
    
    int get_rowsNo() const;
    int get_colNo() const;
    
};


#endif
