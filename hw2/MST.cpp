//
//  MST.cpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/2.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "MST.hpp"

MST::MST(int verticeNum,std::vector<EdgeNode> &MSTedge)
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
    n=static_cast<int>(MSTedge.size());
    for(int i=0;i<n;i++)
    {
        add_edge(MSTedge[i].v1,MSTedge[i].v2,MSTedge[i].weight);
    }
    
}
