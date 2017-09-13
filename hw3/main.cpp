//
//  main.cpp
//  hex
//
//  Created by Eric on 2017/9/6.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include "hexboard.hpp"
#include <ctime>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    int size=7;
    class hexboard hexgame(size);
    int x; int y;
    srand(time(NULL));
    while(true)
    {
        do
        {
            x=rand()%size;
            y=rand()%size;
        }while(!hexgame.isBlank(x,y));
        hexgame.play(x,y,player::BlUE);
        cout<<"BlUE move"<<"("<<x<<","<<y<<")"<<endl;
        if(hexgame.isWin(x,y))
        {
            cout<<"===  BlUE win  ==="<<endl;
            break;
        }
        hexgame.show();
        
        do
        {
            x=rand()%size;
            y=rand()%size;
            
        }while(!hexgame.isBlank(x,y));
        hexgame.play(x,y,player::RED);
        cout<<"RED move"<<"("<<x<<","<<y<<")"<<endl;
        if(hexgame.isWin(x,y))
        {
            cout<<"===  RED win  ==="<<endl;
            break;
        }
        
        hexgame.show();
    }
    
    hexgame.show();
    
    return 0;
}

