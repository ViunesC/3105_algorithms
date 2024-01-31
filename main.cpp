#include <iostream>
#include "StableMatching/stableMatching.h"
#include "Graph/Graph.h"
#include "DirectedGraph/DirectedGraph.h"
#include "Greedy/Greedy.h"
#include "WeightedGraph/WeightedGraph.h"
#include <fstream>


Interval* createInput(std::string fileName, int* number) {
    std::ifstream file(fileName);
    std::string text, name, start;
    int n = 0,c = 0;
    size_t pos;

    // read N
    while (std::getline(file,text)) {
        n++;
    }
    file.close();
    std::ifstream file1(fileName);

    auto* nlist = new Interval[n];
    while (std::getline(file1,text)) {
        name = text.substr(0, 1);
        text.erase(0, 2);

        pos = text.find(' ');
        start = text.substr(0, pos);
        text.erase(0, pos+1);

        Interval i(name, std::stoi(start), std::stoi(text));
        nlist[c] = i;
        ++c;
    }

    *number = n;
    file1.close();

    return nlist;
}

WeightedGraph::WeightedGraph createInput(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::string v, weight;
    char u;
    WeightedGraph::WeightedGraph wg;

    // read N
    while (std::getline(file,line)) {
        wg.addVertex(line[0] - '0');
        // std::cout << "Adding vertex" << line[0] << std::endl;
    }
    file.close();
    std::ifstream file1(fileName);
    line.clear();

    while (std::getline(file1,line)) {
        u = line[0];
        for (auto it = line.begin();it != line.end();++it) {
            if (*it == '(') {
                ++it;
                while (*it != ',') {
                    v.push_back(*it);
                    ++it;
                }
                ++it;
                while (*it != ')') {
                    weight.push_back(*it);
                    ++it;
                }
                // std::cout << "Adding edge (" << u << "," + v + "," + weight << ")" << std::endl;
                wg.addEdge(u - '0', std::stoi(v), std::stoi(weight));
                v.clear();
                weight.clear();
            }
        }
    }

    file1.close();

    return wg;
}

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

    // Greedy: interval algorithms
    /*Greedy::Greedy gdy;
    int n = 999;
    Interval* list1 = createInput("input1.txt", &n);
    gdy.find_maxSubset(list1, n);

    Interval* list = createInput("input0.txt", &n);
    gdy.find_minRoomReq(list,n);

    delete[] list1;
    delete[] list;*/

    // Greedy: shortest-path-problem (dijkstra's algorithm)
    /*WeightedGraph::WeightedGraph wg = createInput("input2.txt");
    wg.shortest_path(0);*/

    WeightedGraph::WeightedGraph wg1 = createInput("input3.txt");
    //wg1.printAll();
    wg1.primMST(1);



    return 0;
}
