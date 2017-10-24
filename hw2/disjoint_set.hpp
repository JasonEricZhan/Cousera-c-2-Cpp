//
//  disjoint_set.hpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/1.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef disjoint_set_hpp
#define disjoint_set_hpp

#include <vector>


class disjointset
{
public:
    disjointset() {};
    
    disjointset(int setNum);
    
    void unionSets(int x, int y);
    
    int findSet(int x);
    
    int findheight(int x);
    
    ~disjointset();
    
private:
    std::vector<int> sets;
};

#endif /* disjoint_set_hpp */
