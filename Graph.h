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
        Node **adjacent_nodes;
    };

    class Graph {
    private:
        int numNodes;
        int capacity;
        Node *node_list;
        void extend_list();
        void dfsUtil(Node *v, std::string *output, std::set<int> *explored);
        bool bipartiteUtil(Node *v, std::set<int> *explored);
        static bool isConnected(Node *u, Node *v);
    public:
        Graph();
        ~Graph();
        void bfs();
        void dfs();
        void bipartite();
        bool addNode(Node node);
        void addEdges(int number, int numAdj, std::string list);
        void listAll();
    };

} // Graph

#endif //INC_3105_ALGORITHMS_GRAPH_H
