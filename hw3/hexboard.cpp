//
//  hexboard.cpp
//  hex
//
//  Created by Eric on 2017/9/6.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "hexboard.hpp"
#include <queue>

using namespace std;




hexboard::hexboard()
{
    ;
}

hexboard::hexboard(int size_int)
{
    size=size_int;
    line = "\\";    // add \ or it will cause error
    record=vector < vector<char> >(size, vector<char>(size,'.'));
    for (int i=1; i<size; i++)
    {
       {
          line += " / \\";
       }
       
    }
    

}


void hexboard::play(int x,int y, player side)
{
    if(record[x][y]==Blank)
    {
        if(side==player::BlUE)
        {
           record[x][y]=Blue;
        }
        if(side==player::RED)
        {
            record[x][y]=Red;
        }

    }
}

bool hexboard::isBlank(int x,int y)
{
    if(record[x][y]==Blank)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hexboard::inBoard(int x, int y)
{
    return x>=0 && x<size && y>=0 && y<size;
}


void hexboard::checkBorder(int x, int y,
                            std::vector<bool> &flags, char side)
{
    if (side == Red)
    {
        if (y == 0)
            flags[0] = true;
        if (y == size - 1)
            flags[1] = true;
    }
    else if (side == Blue)
    {
        if (x == 0)
            flags[0] = true;
        if (x == size - 1)
            flags[1] = true;
    }
}

//Use BFS to check
bool hexboard::isWin(int x, int y)
{
    queue<pair<int, int> > trace;
    vector<vector<bool> > visited(size, vector<bool>(size,false));
    flags=std::vector<bool>(2,false);
    
    char char_side = record[x][y];
    trace.emplace(make_pair(x, y));
    visited[x][y] = true;
    while (!trace.empty())
    {
        auto top = trace.front();
     
        checkBorder(top.first, top.second, flags, char_side);
        trace.pop();
        
        for (int i=0; i<6; i++)
        {
           int current_x=top.first+dirs[i][0];
           int current_y=top.second+dirs[i][1];
           if(inBoard(current_x,current_y) &&
                    visited[current_x][current_y]==false &&
                    record[current_x][current_y]==char_side)
            {
                visited[current_x][current_y]=true;
                trace.emplace(make_pair(current_x, current_y));
            }
                 
            
         }
     }
     
    
    return flags[0] && flags[1];
}




void hexboard::show()
{
    string space="";
    for(int i=0; i<size; i++)
    {
        cout<<space;
        for(int j=0; j<size; j++)
        {
            cout<<record[i][j];
            if(j==size-1)
            {
                break;
            }
            cout<<" _ ";
        }
        if(i==size-1)
        {
            break;
        }
        space+=' ';
        cout<<" "<<endl;
        cout<<space<<line;
        cout<<" "<<endl;
        space+=' ';
    }
    cout<<" "<<endl;
}

hexboard::~hexboard()
{
    ;
}
