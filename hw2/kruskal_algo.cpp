//
//  kruskal_algo.cpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/1.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "kruskal_algo.hpp"
#include <algorithm>



kruskal::kruskal()
{
    ;
}

bool weightcompare(const EdgeNode a,const EdgeNode b)
{
    return a.weight < b.weight;
}

int kruskal::generateMST(graph g, std::vector<EdgeNode> &MSTedges)
{
    
    int verticeNum = g.vertex_number();
    vector<EdgeNode> edges;//the set of edges of the graph
    for (int i=0; i<verticeNum; i++)
    {
        for (int j=0; j<=i; j++)
        {
            if (g.isadjacent(i, j))
            {
                edges.push_back(EdgeNode(i, j, g.getedge_value(i,j)));
            }
        }
    }

    int en=static_cast<int>(edges.size());
    class disjointset  E(en);
    std::sort (edges.begin(), edges.end(),weightcompare);//false then change
    int weight_sum=0;
    //start building MST
    for(int i=0;i<en;i++)
    {
        if(E.findSet(edges[i].v1)!=E.findSet(edges[i].v2))
        {
          E.unionSets(edges[i].v1, edges[i].v2);
          weight_sum+=edges[i].weight;
          MSTedges.push_back(EdgeNode(edges[i].v1,edges[i].v2
                                      , g.getedge_value(edges[i].v1,edges[i].v2)));
        }
    }
    
    
    return weight_sum;
}

kruskal::~kruskal()
{
    ;
}
