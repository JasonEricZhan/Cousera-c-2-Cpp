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



void relax(int u,int v,graph &g)
{
    if(g.vertexqueue[v].distance > g.vertexqueue[u].distance
       +g.getedge_value(u,v))
    {
        g.vertexqueue[v].distance=g.vertexqueue[u].distance
        +g.getedge_value(u,v);
        g.vertexqueue[v].parent=u;
    }
}



void ShortestPath::path(graph &g,int v1,int v2)
{
    //cout<<"start"<<endl;
    //Dijakstra:
    PriorityQueue *p=new PriorityQueue;
    for(int i = v1+1;i<v2+1;i++)
    {
        QueueNode v;
        v.vertex=i;
          g.vertexqueue[i].distance=g.getedge_value(v1,i);
        
           v.priority=g.vertexqueue[i].distance;
           if(g.isadjacent(v1,i))
           {
             g.vertexqueue[i].parent=v1;
           }
        
        p->insert(v);
    }
    g.vertexqueue[v1].distance=0;
    g.vertexqueue[v1].parent=v1;
    while(p->size()>1)
    {
        QueueNode min=p->remove_min();
        for(int i=v1;i<v2+1;i++)
        {
                if(g.isadjacent(min.vertex,i) && i!=min.vertex)
                {
                    relax(min.vertex,i,g);
                }
        }
        
    }
    //start record
    if(g.vertexqueue[v2].parent==-1)
    {
        cout<<"no such path"<<endl;
    }
    else
    {
        //cout<<"path is"<<endl;
        //cout<<v2<<endl;
        pathQueue.push_back(v2);
        back_track(v1,g.vertexqueue[v2].parent,g.vertexqueue);
    }
}


int ShortestPath::path_size(graph &g,int v1,int v2)
{
    path(g,v1,v2);
    if(g.vertexqueue[v2].parent!=-1)
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
