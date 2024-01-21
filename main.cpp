#include <iostream>
#include "stableMatching.h"
#include "Graph.h"
#include "DirectedGraph.h"
#include "Greedy.h"

int main() {
    // Gale-shapley algorithm
    /*int N = 3;
    int **mp = new int*[N];
    for (int i=0;i<N;++i) {
        mp[i] = new int[N];
    }

    int **wp = new int*[N];
    for (int r=0;r<N;++r) {
        wp[r] = new int[N];
    }

    mp[0][0] = 2;
    mp[0][1] = 1;
    mp[0][2] = 0;
    mp[1][0] = 2;
    mp[1][1] = 0;
    mp[1][2] = 1;
    mp[2][0] = 2;
    mp[2][1] = 0;
    mp[2][2] = 1;

    wp[0][0] = 2;
    wp[0][1] = 0;
    wp[0][2] = 1;
    wp[1][0] = 1;
    wp[1][1] = 0;
    wp[1][2] = 2;
    wp[2][0] = 2;
    wp[2][1] = 1;
    wp[2][2] = 0;

    stableMatching::stableMatching matching(N, mp, wp);
    matching.gale_shapley();*/

    // bfs and dfs
    /*Graph::Graph g;
    Graph::Graph g1;
    Graph::Graph g2;

    g.addNode({1});
    g.addNode({2});
    g.addNode({3});
    g.addNode({4});
    g.addNode({5});
    g.addNode({6});
    g.addNode({7});
    g.addNode({8});

    g.addEdges(1,3,"2 4 5");
    g.addEdges(2,3,"1 3 4");
    g.addEdges(3,1,"2");
    g.addEdges(4,3,"1 2 6");
    g.addEdges(5,2,"1 7");
    g.addEdges(6,2,"4 7");
    g.addEdges(7,2,"5 8");
    g.addEdges(8,1,"7");

    g1.addNode({1});
    g1.addNode({2});
    g1.addNode({3});
    g1.addNode({4});
    g1.addNode({5});
    g1.addNode({6});
    g1.addNode({7});
    g1.addNode({8});

    g1.addEdges(1,2,"2 3");
    g1.addEdges(2,2,"1 3");
    g1.addEdges(3,4,"1 2 5 7");
    g1.addEdges(4,2,"6 8");
    g1.addEdges(5,1,"3");
    g1.addEdges(6,2,"4 7");
    g1.addEdges(7,3,"3 6 8");
    g1.addEdges(8,2,"4 7");

    g2.addNode({1});
    g2.addNode({2});
    g2.addNode({3});
    g2.addNode({4});
    g2.addNode({5});
    g2.addNode({6});
    g2.addEdges(1,2,"2 4");
    g2.addEdges(2,3,"1 3 5");
    g2.addEdges(3,4,"2 4 5 6");
    g2.addEdges(4,2,"1 3");
    g2.addEdges(5,3,"2 3 6");
    g2.addEdges(6,2,"3 5");


    //g.bfs();
    //g.listAll();
    //g1.dfs();
    //g2.bipartite();*/

    // Connectivity and Topological sort
    /*DirectedGraph::DirectedGraph g2;
    g2.addNode(0);
    g2.addNode(1);
    g2.addNode(2);
    g2.addNode(3);
    g2.addNode(4);
    g2.addNode(5);
    g2.addEdge(5,0);
    g2.addEdge(5,2);
    g2.addEdge(2,3);
    g2.addEdge(3,1);
    g2.addEdge(4,0);
    g2.addEdge(4,1);

    //g2.listAll();
    g2.connectivity();
    //g2.topoSort();*/

    Greedy::Greedy gdy;
    Interval i1("A", 0, 6);
    Interval i2("B", 2, 6);
    Interval i3("C", 5, 3);
    Interval i4("D", 6, 4);
    Interval i5("E", 8, 3);
    Interval i6("F", 9, 4);
    Interval i7("G", 10, 4);
    Interval i8("H", 13, 3);
    Interval i9("I", 14, 2);

    Interval* list = new Interval[9];
    list[0] = i1;
    list[1] = i2;
    list[2] = i3;
    list[3] = i4;
    list[4] = i5;
    list[5] = i6;
    list[6] = i7;
    list[7] = i8;
    list[8] = i9;

    gdy.find_maxSubset(list, 9);

    delete[] list;

    return 0;
}
