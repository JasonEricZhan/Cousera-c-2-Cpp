//
//  graph.hpp
//  c++dijktras
//
//  Created by Eric on 2017/7/21.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include<vector>
using namespace std;

struct vertex
{
    double distance;
    int parent;
};

class graph
{
public:
    graph(){}   //need to add {},because not in cpp
    graph(int verticeNum);
    graph(int verticeNum, double density);
    int vertex_number();
    int edge_number();
    bool isadjacent(int v1,int v2);
    int  neighbors_num(int v);
    void add_edge(int v1,int v2,int cost);
    void delete_edge(int v1,int v2);
    int getedge_value(int v1,int v2);
    void setedge_value(int v1,int v2,int value);
    ~graph();


    int edge_num;
    

    std::vector<vertex> vertexqueue;
private:
    std::vector<std::vector<int> > adMatrix;
    std::vector<std::vector<double> > costMatrix;
    

};



#endif /* graph_hpp */
