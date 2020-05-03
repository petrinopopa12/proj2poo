//
//  Game.hpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include "Map.hpp"
#include <vector>

class Game {
   Map *m;
    
public :
    
    Game();
    void runda();
    void initial();
    
    ~Game();
};

#endif 
