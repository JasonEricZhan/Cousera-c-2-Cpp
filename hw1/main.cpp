//
//  main.cpp
//  c++upload
//
//  Created by Eric on 2017/7/24.
//  Copyright © 2017年 Eric. All rights reserved.
//
#include <iostream>
#include "graph.hpp"
#include "shortestpath.hpp"
#include <limits>

using namespace std;

int main()
{
    double densities[3] = {0.2, 0.4, 0.5};
    int verticeNum = 50;
    
    for (int i=0; i<3; i++)
    {
        int sum = 0;
        int count = 0;
        class graph graph(verticeNum, densities[i]);
        
        cout<<"graph "<<i<<endl;
        for (int n=1; n<10; n++)
        {
            ShortestPath sp;
            int pathSize=sp.path_size(graph,0,n);
            
            if (pathSize != numeric_limits<int>::infinity())
            {
                sum += pathSize;
                count++;
            }
        }
        
        cout << "For the graph with density = " << densities[i];
        cout << ", the average path length = " <<
        (static_cast<double>(sum) / count) << endl;
    }
    
    return 0;
    
}
