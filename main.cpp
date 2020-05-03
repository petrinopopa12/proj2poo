//
//  main.cpp
//  proj2poo
//
//  Created by Petrino Popa on 30/04/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "Game.hpp"
#include "Map.hpp"
#include <vector>

int  main() {

    srand(time(NULL));
    
    Game Survival;
    cout<<"\n Harta initiala: "<<endl;
    Survival.initial();
    cout<<endl;
    cout<<" A - 1000 Putere ; 200 Miscare"<<endl;
    cout<<" B - 600 Putere ; 600 Miscare"<<endl;
    cout<<" C - 200 Putere ; 1000 Miscare"<<endl;
    int i, nr=0;
    
    do {
        nr++;
        cout<<"\n Runda nr. "<<nr;
        Survival.runda();
        
        cout << "\n\n Continuare - 1 , STOP - 0\n->";
        cin >> i;
    } while(i == 1);
    cout << endl;
    cout <<"GAME OVER"<< endl<< endl;
    
    return 0;
}

