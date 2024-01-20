//
// Created by Re_Innocence on 2024/1/18.
//

#ifndef INC_3105_ALGORITHMS_DIRECTEDGRAPH_H
#define INC_3105_ALGORITHMS_DIRECTEDGRAPH_H
#define DEF_CAPACITY 10

#include <set>
#include <queue>
#include <iostream>

namespace DirectedGraph {
struct Pair {
    int value;
    std::set<int> connected_nodes;
    int get_numConnected();
    void add_edge(int v);
    void remove_edge(int v);
    void removeAll();
};

class DirectedGraph {
private:
    int numNodes;
    int capacity;
    Pair *adjacencyList;
    void extend();
    Pair* findNode(int u);
    DirectedGraph copy();
    DirectedGraph reverse();
public:
    DirectedGraph();
    ~DirectedGraph();
    void addNode(int u);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    void removeNode(int u);
    void connectivity();
    void topoSort();
    int bfs();
    void listAll();
    };

} // DirectedGraph

#endif //INC_3105_ALGORITHMS_DIRECTEDGRAPH_H
