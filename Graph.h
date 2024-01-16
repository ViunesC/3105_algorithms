//
// Created by Re_Innocence on 2024/1/16.
//

#ifndef INC_3105_ALGORITHMS_GRAPH_H
#define INC_3105_ALGORITHMS_GRAPH_H

#define DEFAULT_CAPACITY 10
#include <iostream>
#include <set>
#include <queue>

namespace Graph {
    struct Node {
        int value;
        int numAdjacent;
        Node *adjacent_nodes;
    };

    class Graph {
    private:
        int numNodes;
        int capacity;
        Node *node_list;
        void extend_list();
    public:
        Graph();
        ~Graph();
        void bfs();
        void dfs();
        bool addNode(Node node);
        void addEdges(int number, int numAdj, std::string list);
        void listAll();
    };

} // Graph

#endif //INC_3105_ALGORITHMS_GRAPH_H
