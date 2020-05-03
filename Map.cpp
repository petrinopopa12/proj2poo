//
//  Map.cpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#include "Map.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#include "Map.hpp"

Map::Map(const int row, const int col):rowsNo(row), colNo(col) {
    agents_matrix = new Agent**[row];
    for(int i=0; i<=row ;i++)
        agents_matrix[i] = new Agent*[col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            agents_matrix[i][j]=NULL;
}

Map::~Map() {
    while(agents.size()>0)
        agents.pop_back();
    for(int i=0;i<rowsNo;i++)
        for(int j=0;j<colNo;j++)
            if(agents_matrix[i][j]!=NULL) {
                delete agents_matrix[i][j];
                agents_matrix[i][j]=NULL;
            }
    for(int i=0; i < rowsNo; i++) {
        delete[] agents_matrix[i];
        agents_matrix[i]=NULL;
    }
}

void Map::add_agent(const Agent *ag,const int row,const int col) {
    agents_matrix[row][col] =(Agent*) ag;
    bool ok = true;
    for(int i=0;i<agents.size();i++)
         if(ag==agents[i])
             ok = false;
    if(ok == true)
        agents.push_back ((Agent*)ag);
}
 
void Map::remove_agent(const Agent *agent) {
    agents_matrix[agent->position.row][agent->position.col] = NULL;
    int i = 0;
    while(i < agents.size() && agent!=agents[i])
        i++;
    for(int j=i;j<agents.size()-1;j++)
        agents[j] = agents[j+1];
    agents.pop_back();
}

Agent* Map::get_agent_position(const int row,const int col) const{
    return agents_matrix[row][col];
}

vector<Agent*> Map::get_all_agents()const {
    return agents;
}

void Map::move_agent( Agent* const agent, const int new_row, const int new_col) {
    Agent::Position p(new_row,new_col),
        q = agent->get_position();
    agents_matrix[q.row][q.col] = NULL;
    agent->set_position(p);
    agents_matrix[p.row][p.col] = agent;
}


int Map::get_rowsNo() const {
    return rowsNo;
}

int Map::get_colNo() const {
    return colNo;
}

