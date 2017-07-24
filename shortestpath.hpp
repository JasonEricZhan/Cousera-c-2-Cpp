//
//  shortestpath.hpp
//  c++dijktras
//
//  Created by Eric on 2017/7/22.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef shortestpath_hpp
#define shortestpath_hpp

#include <iostream>
#include"graph.hpp"
#include"PriorityQueue.hpp"




class ShortestPath
{
public:
    ShortestPath();
    void back_track(int start,int parent,vector<vertex> &vertexMatrix);
    void path(graph &g,int v1,int v2);
    int path_size(graph &g,int v1,int v2);
    ~ShortestPath();
    
    vector<int> pathQueue;

};


#endif /* shortestpath_hpp */
