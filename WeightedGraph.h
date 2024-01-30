//
// Created by Re_Innocence on 2024/1/20.
//

#ifndef INC_3105_ALGORITHMS_WEIGHTEDGRAPH_H
#define INC_3105_ALGORITHMS_WEIGHTEDGRAPH_H

#include <iostream>
#include <set>
#include <vector>
#include <queue>

#define INF_DIST 0x3f3f3f3f

namespace WeightedGraph {
    struct Edge {
    private:
        int weight;
        int toVertex;
    public:
        Edge(int v, int weight);
        int getWeight();
        int getVertexConnected();
    };

    struct Vertex {
    private:
        int value;
        std::vector<Edge> edgeList;
    public:
        Vertex(int value);
        int getValue();
        size_t getNumConnected();
        std::vector<Edge>* getEdges();
        bool isConnected(int v);
        void addEdge(int v, int weight);
        void removeEdge(int v);
    };

    typedef std::pair<int, Vertex*> myPair;

    class WeightedGraph {
    private:
        std::vector<Vertex> adjacencyList;
        bool isExist(int value);
        int find(int value);
    public:
        WeightedGraph();
        void addVertex(int value);
        void removeVertex(int value);
        void addEdge(int u, int v, int weight);
        void removeEdge(int u, int v);
        size_t getN();
        void shortest_path(int u);
        void printAll();
    };
} // WeightedGraph



#endif //INC_3105_ALGORITHMS_WEIGHTEDGRAPH_H
