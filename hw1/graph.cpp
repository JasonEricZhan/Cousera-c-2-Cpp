//
//  graph.cpp
//  c++dijktras
//
//  Created by Eric on 2017/7/21.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "graph.hpp"
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
//time in c
#include <time.h>
//
#include <limits>

using namespace std;


int compute(const vector<vector<double> > costmatrix)
{
    int sum=0;
    for(int i=0;i<costmatrix.size();i++)
    {
        for(int j=0;j<costmatrix.size();j++)
        {
            if(costmatrix[i][j]!=numeric_limits<double>::infinity())
            {
                sum+=1;
            }
        }
    }
    return sum/2;
}


void graph::add_edge(int v1,int v2,int cost)
{
    if(costMatrix[v1][v2]!=numeric_limits<double>::infinity())
    {
        cout<<"already connected"<<endl;
        return;
    }
    double cost_d=static_cast<double>(cost);
    costMatrix[v1][v2]=cost_d;
    costMatrix[v2][v1]=cost_d;
    adMatrix[v1][v2]=1;
    adMatrix[v2][v1]=1;
    
}

graph::graph(int verticeNum)
{
    if (verticeNum <= 0)
    {
        verticeNum = 0;
        return;
    }
    
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
}

graph::graph(int verticeNum, double density)
{
    if (verticeNum <= 0)
    {
        verticeNum = 0;
        return;
    }
    
    adMatrix = vector<vector<int> >(verticeNum, vector<int>(verticeNum));
    //std::vector<std::vector<int>> array_2d(rows, std::vector<int>(cols, 0))
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
    srand(time(0));
    const int RANGE = 10;
    for (int i=0; i<verticeNum; i++)
    {
        
        for (int j=0; j<i+1; j++)
        {
            double prob = (rand() % 100) / 100.0;
            
            if (prob < density)
            {
                int value = rand() % RANGE + 1;
                if(i!=j)
                {
                    add_edge(i, j, value);
                }
            }
        }
    }
}

int graph::vertex_number()
{
    
    return static_cast<int>(adMatrix.size());
}

int graph::edge_number()
{
    edge_num=compute(costMatrix);
    return edge_num;
    
}

bool graph::isadjacent(int v1,int v2)
{
    if(adMatrix[v1][v2]==1 && adMatrix[v2][v1]==1)
    {
        return true;
    }
    return false;
}

int graph::neighbors_num(int v)
{
    int n=static_cast<int>(adMatrix.size());
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=adMatrix[v][i];
    }
    return sum;
}



void graph::delete_edge(int v1,int v2)
{
    if(costMatrix[v1][v2]==numeric_limits<double>::infinity())
    {
        cout<<"already disconnected"<<endl;
        return;
    }
    costMatrix[v1][v2]= numeric_limits<double>::infinity();
    costMatrix[v2][v1]= numeric_limits<double>::infinity();
    adMatrix[v1][v2]=0;
    adMatrix[v2][v1]=0;
}

int graph::getedge_value(int v1,int v2)
{
    return costMatrix[v1][v2];
}

void graph::setedge_value(int v1,int v2,int cost)
{
    if(adMatrix[v1][v2]==0)
    {
        cout<<"It's disconnected"<<endl;
        return;
    }
    costMatrix[v1][v2]=cost;
}

graph::~graph()
{
    
}
