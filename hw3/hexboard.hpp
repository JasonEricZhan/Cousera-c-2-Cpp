//
//  hexboard.hpp
//  hex
//
//  Created by Eric on 2017/9/6.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef hexboard_hpp
#define hexboard_hpp

#include <iostream>
#include<vector>

enum class player { BlUE, RED };

class hexboard
{
public:
    hexboard(){size=0;};
    hexboard(int size);
    void play(int x,int y, player side);
    bool isBlank(int x,int y);
    void checkBorder(int x, int y,
                     std::vector<bool> &flags, char side);
    bool isWin(int x, int y);
    bool inBoard(int x, int y);
    void show();
    ~hexboard();
    
private:
    int size;
    std::vector < std::vector<char> > record;
    const int dirs[6][2]=
    {
        {-1, 0}, {-1, 1}, // top left, top right
        {0, -1}, {0, 1},  // left, right
        {1, -1}, {1, 0},  // buttom left, buttom right
    };
    const  char Blue = 'B';
    const  char Red = 'R';
    const  char Blank = '.';
    std::vector<bool> flags;
    std::string line;
    
    
};


#endif /* hexboard_hpp */
