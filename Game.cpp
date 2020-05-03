//
//  Game.cpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#include "Game.hpp"
#include "Map.hpp"
#include "A.hpp"
#include "Agent.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Game::Game(){
    cout<<" START"<<endl;

    int x,y,z;
    //cout<<"Dimensiune harta: ";
    cin>>x>>y;
    m = new Map(x,y);
    //cout<<"Numarul agentilor: ";
    cin>>z;
    for(int i=1; i<=z; i++) {
        Agent::Position p(0,0);
        char c;
        //cout<<"Tip agent "<<i<<": ";
        cin>> c>> p.row >> p.col;;
        //cout<<"Pozitie agent "<<i<<": ";
        //cin>> p.row >> p.col;
        Agent *a;
        if(c=='a')
            a = new agent_A(p);
        else
            if(c=='b')
                a = new agent_B(p);
            else
                if(c=='c')
                    a = new agent_C(p);
        m->add_agent(a,p.row,p.col);
    }
}

//afisare harta
ostream &operator <<(ostream &f,Map &map_matrix) {
    f <<endl <<" ";
    for(int i=0; i<2*map_matrix.get_colNo();i++)
        f << "_";
    f << endl;
    for(int i=0; i<map_matrix.get_rowsNo(); i++) {
         f<<"|";
        for(int j=0; j<map_matrix.get_colNo(); j++)
            if(map_matrix.get_agent_position(i,j)!=NULL)
                f <<map_matrix.get_agent_position(i,j)->get_agent_type()<<" ";
            else
                f<<" "<<" ";
        f << "|";
        f << endl;
    }
    f <<" ";
    for(int i=0; i<2*map_matrix.get_colNo();i++)
        f << "_";
    return f;
}
 
void Game::initial() {
    cout << *m;
}

//desfasurarea rundelor
void Game::runda() {
    Agent::Position p1(0,0);
    
    int i = 0;
    vector<Agent*> agents_array;
    agents_array = m->get_all_agents();
    
    while (i < agents_array.size()) {
        Agent *a1;
        a1 = agents_array[i];
        p1 = a1->choose_new_position(*m);
        string t1 = a1->get_agent_type();
        
        if(!m->get_agent_position(p1.row, p1.col)) {
            m->move_agent(a1, p1.row, p1.col);
            i++;
        }
        else {Agent *c = m->get_agent_position(p1.row, p1.col);
            string t2 = c->get_agent_type();
            //if(t1.compare(t2)==0)
                //p1 = a1->choose_new_new_position(*m);
                //else{
            //il fac pe A cel mai "puternic" dintre agenti, urmat de B
                if ((t1.compare("A")==0) || ((t2.compare("A")!=0)&&(t1.compare("B")==0))||((t2.compare("A")!=0)&&(t2.compare("B")!=0))){
                int j = 0;
                bool ok = false;
                while(j<agents_array.size() && ok!=true)
                    if(c!=agents_array[j]) {
                        j++;
                        ok=true;
                    }
                m->remove_agent(c);
                m->move_agent(a1,p1.row,p1.col);
                delete c;
                if(j>i)
                    i++;
                agents_array=m->get_all_agents();
                }
            else{
                m->remove_agent(a1);
                delete a1;
                agents_array=m->get_all_agents();
            }
        }
        //}
    }
    //afisez noua harta
    cout<<endl<<*m;
    cout<<endl;
    cout<<endl<<"Agenti ramasi: "<<agents_array.size()<<endl;
    int ta=0,tb=0,tc=0;
    int l=0;
    while (l < agents_array.size()) {
        Agent *a2;
        a2 = agents_array[l];
        string t = a2->get_agent_type();
        if(t.compare("A")==0)
            ta++;
        if(t.compare("B")==0)
            tb++;
        if(t.compare("C")==0)
            tc++;
        l++;
    }
    cout<<endl<<"Echipa A: "<<ta;
    cout<<endl<<"Echipa B: "<<tb;
    cout<<endl<<"Echipa C: "<<tc;
}

Game::~Game() {
    delete m;
}

