//
//  disjoint_set.cpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/1.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "disjoint_set.hpp"

using namespace std;

disjointset::disjointset(int setNum)
{
    sets=vector<int>(setNum,-1);
}


void disjointset::unionSets(int x, int y)
{
    int root1=findSet(x);
    int root2=findSet(y);
    if(root1==root2)
    {
        return;
    }
    else
    {
        //rank by height
        int height1=findheight(x);
        int height2=findheight(y);
        if(height1>height2)
        {
            sets[root2]=root1;
            
        }
        else
        {
            sets[root1]=root2;
        }
    }
}

int disjointset::findSet(int x)
{
    std::vector<int> temp;
    while (sets[x] != -1)
    {
        temp.push_back(x);
        x = sets[x];
    }
    
    // compress the path
    for (auto it = temp.begin(); it != temp.end(); ++it)
    {
        sets[*it]= x;  //be careful is element
    }
    
    return x;
}


int disjointset::findheight(int x)
{

    int sum=0;
    while (sets[x] != -1)
    {
        x = sets[x];
        sum++;
    }
    return sum;
}


disjointset::~disjointset()
{
    
}
