//
//  PriorityQueue.cpp
//  c++dijktras
//
//  Created by Eric on 2017/7/20.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "PriorityQueue.hpp"

using namespace std;



PriorityQueue::PriorityQueue()
{
    
}




void adjust(vector<QueueNode>& array ,int r ,int n)
{
    
    QueueNode k=array[r];
    int j;
    for(j=r*2;j<=n; j=j*2)
    {
        if (array[j].priority > array[j+1].priority&& j<n ) j++;
        ///junp out of range n may make a mistake
        if(k.priority<array[j].priority)
            break;
        else
            array[j/2]=array[j];
    }
    array[j/2]=k;
}



bool PriorityQueue::iscontains(const QueueNode queue_element)
{
    for (vector<QueueNode>::iterator it = minHeap.begin() ; it != minHeap.end(); ++it)
    {
        if(queue_element.vertex==(*it).vertex)
        {
            return true;
        }
    }
    return false;
}


void PriorityQueue::chgPrioirity(QueueNode node,int priority)
{
    int n=static_cast<int>(minHeap.size());
    bool tag=false;
    for (int i=1 ; i<n+1; i++)
    {
        if(node.vertex==minHeap[i].vertex)
        {
            minHeap[i].priority=priority;
            tag=true;
        }
    }
    if(tag==false)
    {
        cout<<"not include"<<endl;
        return;
    }
    for(int i=(n-1)/2;i>=1;i--)
        adjust(minHeap,i,n-1) ;
}




QueueNode PriorityQueue::remove_min()
{
    QueueNode min=minHeap[1];
    QueueNode x;
    x=minHeap.back();
    minHeap[1]=x;
    int n;
    n=static_cast<int>(minHeap.size());
    if (n>1)
    {
        minHeap.pop_back();
        minHeap.resize(n-1);
        for(int i=(n-2)/2;i>=1;i--)
            adjust(minHeap,i,n-2) ;
    }
    else
    {
        minHeap.pop_back();
        minHeap.resize(0);
        cout<<"no element"<<endl;
    }
    
    return min;
}



void PriorityQueue::insert(QueueNode queue_element)
{
    //buttom up
    
    if(minHeap.empty())
    {
        minHeap.resize(2);
        minHeap[0].priority=numeric_limits<double>::infinity();
        minHeap[1]=queue_element;
    }
    else
    {
        minHeap.push_back(queue_element);
        int n=static_cast<int>(minHeap.size());
        n-=1;
        for(int i=n/2;i>=1;i--)
            adjust(minHeap,i,n) ;
    }
}


int PriorityQueue::size()
{
    return static_cast<int>(minHeap.size());
}

int PriorityQueue::top()
{
    assert(static_cast<int>(minHeap.size()) > 1);
    
    return minHeap[1].vertex;
}



PriorityQueue::~PriorityQueue()
{
    
}
