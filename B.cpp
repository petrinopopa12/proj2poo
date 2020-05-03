//
//  B.cpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#include "B.hpp"
#include "Map.hpp"
#include <iostream>

Agent::Position agent_B::choose_new_position(const Map& map) const {
    Position p(0,0);
    Position limita_min(position.row-1,position.col-1),limita_max(position.row+1,position.col+1);
    int n = map.get_rowsNo();
    int m = map.get_colNo();
    
    bool ok = false;
    int i=limita_min.row,j;
    while(ok == false && i<=limita_max.row) {
        j=limita_min.col;
        p.row = i;
        while(ok == false && j <= limita_max.col) {
            p.col = j;
            if(p.row>=0 && p.row<n && p.col>=0 && p.col<m && !(p==position))
                if(map.get_agent_position(p.row,p.col))
                    ok=true;
            j++;
        }
        i++;
    }
    int x[2] = {2,-2} ,y[2] = {2,-2};
    if (ok == false)
        while (ok == false) {
            int i, j, k;
            i = rand()%2;
            j = rand()%2;
            k = rand()%3;//0-merge pe linie; 1-pe col; 2-ramane pe loc
            if ( k == 0 )
                p.row = position.row+x[i];
            else
                if (k == 1)
                    p.col = position.col+y[j];
            if (p.row >= 0 && p.row<n && p.col >= 0 && p.col<m && map.get_agent_position(p.row,p.col) == NULL)
                ok = true;
        }
   
    
return p;
    
}

/*Agent::Position agent_B::choose_new_new_position(const Map& map) const {
Position p(0,0);
int ok=false;
int x[2] = {1,-1};
int y[2] = {1,-1};
int n = map.get_rowsNo();
int m = map.get_colNo();

if(ok == false)
    while(ok == false) {
        int i,j;
        i = rand()%2;
        j = rand()%2;
        p.row = position.row+x[i];
        p.col = position.col+y[j];
        if(p.row>=0 && p.row<n && p.col>=0 && p.col<m && map.get_agent_position(p.row,p.col) == NULL)
            ok = true;
    }
   
    
return p;
    
}
*/
