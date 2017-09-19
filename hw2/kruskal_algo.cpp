//
//  kruskal_algo.cpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/1.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "kruskal_algo.hpp"
#include <algorithm>



kruskal_MST::kruskal_MST(int verticeNum)
{
    adMatrix = vector<vector<int> >(verticeNum, vector<int>(verticeNum));
    costMatrix = vector<vector<double> >(verticeNum, vector<double>(verticeNum));
    vertexqueue=vector<vertex>(verticeNum);
    int n=static_cast<int>(costMatrix.size());
    for(int i=0;i<n;i++)
    {
        vertexqueue[i].parent=-1;
        vertexqueue[i].distance=numeric_limits<double>::infinity();
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                costMatrix[i][i]=0.00;
            }
            else
            {
                costMatrix[i][j]=numeric_limits<double>::infinity();
            }
        }
    }
    n=static_cast<int>(MSTedges.size());
    
    
    for(int i=0;i<n;i++)
    {
        add_edge(MSTedges[i].v1,MSTedges[i].v2,MSTedges[i].weight);
    }

}

bool weightcompare(const EdgeNode a,const EdgeNode b)
{
    return a.weight < b.weight;
}

int kruskal_MST::generateMST(graph g)
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

kruskal_MST::~kruskal_MST()
{
    ;
}
