//
//  main.cpp
//  kruskal_algo
//
//  Created by Eric on 2017/8/1.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include<vector>
#include <fstream>
#include"graph.hpp"
#include"kruskal_algo.hpp"
#include "disjoint_set.hpp"
#include"MST.hpp"

using namespace std;




int main(int argc, const char * argv[]) {
    
    ifstream infile;
    infile.open("content.txt",ios_base::in);//open the file as ifstream
    std::vector<EdgeNode> MSTedges;
    int cost=-1;
    if ( infile.is_open() )
    {
        //read the file and initailize the graph;
        graph *G=new graph(infile);
        G->show();
        
        class kruskal_MST MST(G->vertex_number());
        cost=MST.generateMST(*G);
        cout<<"=========="<<endl;
        cout<<cost<<endl;
        cout<<"=========="<<endl;
        
        MST.show();

        delete G;G=NULL;
    }
    else
    {
        cout<<"file can't opened"<<endl;
    }
    infile.close();
    return 0;
    
    
}
