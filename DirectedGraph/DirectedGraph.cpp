//
// Created by Re_Innocence on 2024/1/18.
//

#include "DirectedGraph.h"

namespace DirectedGraph {
    DirectedGraph DirectedGraph::reverse() {
        DirectedGraph g = copy();
        for (int i=0;i<g.numNodes;++i) {
            g.adjacencyList[i].removeAll();
            for (int j=0;j<numNodes;++j) {
                for (int v : adjacencyList[j].connected_nodes) {
                    // std::cout << "v:" << v << std::endl;
                    if (v == g.adjacencyList[i].value) {
                        g.addEdge(g.adjacencyList[i].value, adjacencyList[j].value);
                        break;
                    }
                }
            }
        }

        return g;
    }

    DirectedGraph::DirectedGraph() {
        numNodes = 0;
        capacity = 0;
    }

    DirectedGraph::~DirectedGraph() {
        if (numNodes != 0) {
            delete[] adjacencyList;
        }
    }

    void DirectedGraph::connectivity() {
        int first_run = bfs();
        DirectedGraph rg = reverse();
        int second_run = rg.bfs();
        if (first_run == second_run && first_run == numNodes)
            std::cout << "The graph is strongly connected" << std::endl;
        else
            std::cout << "The graph is NOT strongly connected" << std::endl;
    }

    void DirectedGraph::topoSort() {
        DirectedGraph g = copy();
        std::string output;
        bool isRemoved = true;
        std::set<int> explorable;

        while ((g.numNodes != 0) && isRemoved) {
            isRemoved = false;
            explorable.clear();

            for (int i=0;i<g.numNodes;++i) {
                for (int v : g.adjacencyList[i].connected_nodes) {
                    if (explorable.count(v) == 0) {
                        explorable.insert(v);
                    }
                }
            }

            for (int i=0;i<g.numNodes;++i) {
                if (explorable.count(g.adjacencyList[i].value) == 0) {
                    // std::cout << "remove node " << g.adjacencyList[i].value << std::endl;
                    output += std::to_string(g.adjacencyList[i].value) + " ";
                    g.removeNode(g.adjacencyList[i].value);
                    isRemoved = true;
                    break;
                }
            }
        }

        if (output.empty())
            std::cout << "Graph does not have a topological order" << std::endl;
        else
            std::cout << "Topological order is: " << output << std::endl;
    }

    DirectedGraph DirectedGraph::copy() {
        DirectedGraph g;
        std::set<int> *list;
        int x;
        for (int i=0;i<numNodes;++i) {
            g.addNode(adjacencyList[i].value);
        }

        for (int i=0;i<numNodes;++i) {
            x = adjacencyList[i].value;
            list = &adjacencyList[i].connected_nodes;
            for (int it : *list) {
                g.addEdge(x,it);
            }
        }

        return g;
    }

    void DirectedGraph::addNode(int u) {
        if (numNodes == 0) {
            capacity = DEF_CAPACITY;
            adjacencyList = new Pair[capacity];
        }
        if (numNodes == capacity)
            extend();
        adjacencyList[numNodes] = Pair{u};
        ++numNodes;
    }

    void DirectedGraph::addEdge(int u, int v) {
        Pair *x = findNode(u);
        if (x == nullptr)
            return;
        if (findNode(v) == nullptr)
            return;
        x->add_edge(v);
    }

    void DirectedGraph::removeEdge(int u, int v) {
        Pair *x = findNode(u);
        if (x == nullptr)
            return;
        x->remove_edge(v);
    }

    void DirectedGraph::removeNode(int u) {
        for (int i=0;i<numNodes;++i) {
            adjacencyList[i].remove_edge(u);
        }

        for (int i=0;i<numNodes;++i) {
            if (adjacencyList[i].value == u) {
                for (int j=i;j<numNodes-1;++j)
                    adjacencyList[j] = adjacencyList[j+1];
                --numNodes;
                return;
            }
        }

        std::cout << "Cannot remove node " << u << std::endl;
    }

    void DirectedGraph::extend() {
        Pair *newList = new Pair[capacity += DEF_CAPACITY];
        for (int i=0;i<numNodes;++i) {
            newList[i] = adjacencyList[i];
        }

        Pair *temp = adjacencyList;
        adjacencyList = newList;
        delete[] temp;
    }

    Pair *DirectedGraph::findNode(int u) {
        for (int i=0;i<numNodes;++i) {
            if (adjacencyList[i].value == u)
                return &adjacencyList[i];
        }
        std::cout << "Cannot find the node " << u << std::endl;
        return nullptr;
    }

    int DirectedGraph::bfs() {
        if (numNodes == 0)
            return -1;
        if (adjacencyList[0].get_numConnected() == 0) {
            std::cout << "" << std::endl;
            return 0;
        }

        std::set<int> explored;
        std::queue<Pair*> toBeExplored;
        std::string output;
        Pair *current;
        int count = 0;

        // start with node 0 by default
        toBeExplored.push(&adjacencyList[0]);
        while (explored.size() != numNodes) {
            if (toBeExplored.empty())
                break;
            // std::cout << output << std::endl;
            current = toBeExplored.front();
            // std::cout << "current:" << std::to_string(current->value) << std::endl;

            // if the node does not been explored
            if (explored.count(current->value) == 0) {
                // add current node to explored set and string output
                explored.insert(current->value);
                output += std::to_string(current->value) + " ";
                ++count;
                // std::cout << "ADJ:" << current->numAdjacent << std::endl;

                // add its child to toBeExplored
                for (int v : current->connected_nodes) {
                    // std::cout << "add " << v << " into TBE" << std::endl;
                    toBeExplored.push(findNode(v));
                }
            }

            toBeExplored.pop();
        }

        std::cout << output << std::endl;
        return count;
    }

    void DirectedGraph::listAll() {
        for (int i=0;i<numNodes;++i) {
            std::cout << adjacencyList[i].value << ": ";
            for (int v : adjacencyList[i].connected_nodes)
                std::cout << v << ",";
            std::cout << std::endl;
        }
    }

    int Pair::get_numConnected() {
        return connected_nodes.size();
    }

    void Pair::add_edge(int v) {
        connected_nodes.insert(v);
    }

    void Pair::remove_edge(int v) {
        if (connected_nodes.count(v) == 0)
            return;
        connected_nodes.erase(v);
    }

    void Pair::removeAll() {
        connected_nodes.clear();
    }
} // DirectedGraph