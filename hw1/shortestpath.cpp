//
//  shortestpath.cpp
//  c++dijktras
//
//  Created by Eric on 2017/7/22.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "shortestpath.hpp"


using namespace std;

ShortestPath::ShortestPath()
{
    
}

void ShortestPath::back_track(int start,int parent,vector<vertex> &vertexMatrix)
{
    //cout<<parent<<endl;
    pathQueue.insert(pathQueue.begin(),parent);
    if(start==parent)
    {
        return;
    }
    back_track(start,vertexMatrix[parent].parent,vertexMatrix);
}



void relax(int u,int v,vector<vector<double> > &costMatrix,vector<vertex> &vertexMatrix)
{
    if(vertexMatrix[v].distance > vertexMatrix[u].distance
       +costMatrix[u][v])
    {
        vertexMatrix[v].distance=vertexMatrix[u].distance
        +costMatrix[u][v];
        vertexMatrix[v].parent=u;
    }
}



void ShortestPath::path(graph &g,int v1,int v2)
{
    //cout<<"start"<<endl;
    //Dijkstra's algo:
    int n=static_cast<int>(g.costMatrix.size());
    PriorityQueue *p=new PriorityQueue;
    for(int i = v1+1;i<v2+1;i++)
    {
        QueueNode v;
        v.vertex=i;
          g.vertexMatrix[i].distance=g.costMatrix[v1][i];
        
           v.priority=g.vertexMatrix[i].distance;
           if(g.adMatrix[v1][i]==1)
           {
             g.vertexMatrix[i].parent=v1;
           }
        
        p->insert(v);
    }
    g.vertexMatrix[v1].distance=0;
    g.vertexMatrix[v1].parent=v1;
    while(p->size()>1)
    {
        QueueNode min=p->remove_min();
        for(int i=v1;i<v2+1;i++)
        {
                if(g.adMatrix[min.vertex][i]==1 && i!=min.vertex)
                {
                    relax(min.vertex,i,g.costMatrix,g.vertexMatrix);
                }
        }
        
    }
    //start record
    if(g.vertexMatrix[v2].parent==-1)
    {
        cout<<"no such path"<<endl;
    }
    else
    {
        //cout<<"path is"<<endl;
        //cout<<v2<<endl;
        pathQueue.push_back(v2);
        back_track(v1,g.vertexMatrix[v2].parent,g.vertexMatrix);
    }
}


int ShortestPath::path_size(graph &g,int v1,int v2)
{
    path(g,v1,v2);
    if(g.vertexMatrix[v2].parent!=-1)
    {
        if(pathQueue[0]!=v1 || pathQueue.back()!=v2)
        {
            cout<<"build the shortestpath first"<<endl;
        }
        else
        {
            return pathQueue.size();
        }
    }
    return 0;
}



ShortestPath::~ShortestPath()
{
    
}
