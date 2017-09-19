//
//  MST.hpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/2.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef MST_hpp
#define MST_hpp

#include <iostream>
#include"graph.hpp"
#include"kruskal_algo.hpp"

class MST:protected graph
{
public:
    MST(){}
    MST(int verticeNum,std::vector<EdgeNode> &MSTedge);
    
   ~MST(){};
    

};


#endif /* MST_hpp */
