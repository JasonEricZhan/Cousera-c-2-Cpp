//
//  kruskal_algo.hpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/1.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef kruskal_algo_hpp
#define kruskal_algo_hpp

#include <vector>
#include "graph.hpp"
#include "disjoint_set.hpp"



struct EdgeNode
{
    int v1;
    int v2;
    int weight;
    
    EdgeNode(int v1=-1, int v2=-1, int weight=0): v1(v1),v2(v2), weight(weight)
    {
    }
};

class kruskal_MST:public graph
{
    
public:
    kruskal_MST(){};
    kruskal_MST(int verticeNum);
    int generateMST(graph g);
    void setMST(int verticeNum,std::vector<EdgeNode> &MSTedge);
    ~kruskal_MST();

private:
    std::vector<EdgeNode> MSTedges;
    std::vector<EdgeNode> record;
};




#endif /* kruskal_algo_hpp */
