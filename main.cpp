#include <iostream>
#include "stableMatching.h"
#include "Graph.h"

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

    return 0;
}
