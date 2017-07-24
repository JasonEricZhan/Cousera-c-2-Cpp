//
//  PriorityQueue.hpp
//  c++dijktras
//
//  Created by Eric on 2017/7/20.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#define PriorityQueue_hpp

#include <iostream>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <limits>

//the element of priority queue

struct QueueNode
{
    int vertex;
    double priority;
    
    QueueNode(int vertex=-1, double priority=INFINITY):
    vertex(vertex), priority(priority)
    {
    }
};



class PriorityQueue
{
public:
    std::vector<QueueNode> minHeap;
    PriorityQueue();
    
    void chgPrioirity(QueueNode node,int priority);
    QueueNode remove_min();
    bool iscontains(const QueueNode queue_element);
    void insert(QueueNode  queue_element);
    int size();
    int top();
    
    ~PriorityQueue();
    
};




#endif /* PriorityQueue_hpp */

