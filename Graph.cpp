//
// Created by Re_Innocence on 2024/1/16.
//

#include "Graph.h"

namespace Graph {
    Graph::Graph() {
        this->numNodes = 0;
        this->capacity = DEFAULT_CAPACITY;
        node_list = new Node[capacity];
    }

    Graph::~Graph() {
        for (int i=0;i<numNodes;++i) {
            delete[] node_list[i].adjacent_nodes;
        }
        delete[] node_list;
    }

    void Graph::bfs() {
        if (numNodes == 0)
            return;

        std::set<int> explored;
        std::queue<Node*> toBeExplored;
        std::string output;
        Node *current;

        // start with node 0 by default
        toBeExplored.push(&node_list[0]);
        while (explored.size() != numNodes) {
            // std::cout << output << std::endl;
            current = toBeExplored.front();
            // std::cout << "current:" << std::to_string(current->value) << std::endl;

            // if the node does not been explored
            if (explored.count(current->value) == 0) {
                // add current node to explored set and string output
                explored.insert(current->value);
                output += std::to_string(current->value) + " ";
                // std::cout << "ADJ:" << current->numAdjacent << std::endl;

                // add its child to toBeExplored
                for (int i=0;i<current->numAdjacent;++i) {
                    // std::cout << "add " << current->adjacent_nodes[i]->value << " into TBE" << std::endl;
                    toBeExplored.push(current->adjacent_nodes[i]);
                }
            }

            toBeExplored.pop();
        }

        std::cout << output << std::endl;
    }

    void Graph::dfs() {
        std::set<int> explored;
        std::string result;
        if (numNodes == 0)
            return;
        else {
            dfsUtil(&node_list[0], &result, &explored);
        }

        std::cout << result << std::endl;
    }

    bool Graph::addNode(Node node) {
        for (int i=0;i<numNodes;++i) {
            if (node_list[i].value == node.value) {
                std::cout << "Error when adding node: cannot add the node" << std::endl;
            }
        }

        if (numNodes == capacity) {
            extend_list();
        }

        node_list[numNodes] = node;
        ++numNodes;

        return true;
    }

    void Graph::extend_list() {
        Node *new_list = new Node[capacity+=DEFAULT_CAPACITY];
        for (int i=0;i<numNodes;++i) {
            new_list[i] = node_list[i];
        }
        Node *temp = node_list;
        node_list = new_list;

        for (int j=0;j<numNodes;++j) {
            for (int r=0;r<temp[j].numAdjacent;++r) {
                delete temp[j].adjacent_nodes[r];
            }
            delete[] temp[j].adjacent_nodes;
        }
        delete[] temp;
    }

    void Graph::addEdges(int node, int numAdj, std::string list) {
        int count = -1;
        Node **nodes;
        char c;
        for (int i=0;i<numNodes;++i) {
            if (node_list[i].value == node) {
                node_list[i].numAdjacent = numAdj;
                nodes = new Node*[numAdj];

                // Insert adjacent list
                for (int j=0;j<list.length();++j) {
                    c = list[j];
                    if (c != ' ') {
                        for (int k=0;k<numNodes;++k) {
                            if (node_list[k].value == (c-'0')) {
                                nodes[++count] = &node_list[k];
                                break;
                            }
                        }
                    }
                }
                node_list[i].adjacent_nodes = nodes;
                break;
            }
        }
    }

    void Graph::listAll() {
        for (int i=0;i<numNodes;++i) {
            std::cout << std::to_string(node_list[i].value) + ": ";
            for (int j=0;j<node_list[i].numAdjacent;++j) {
                std::cout << std::to_string(node_list[i].adjacent_nodes[j]->value) + " ";
            }
            std::cout << std::endl;
        }
    }

    void Graph::dfsUtil(Node *v, std::string *output, std::set<int> *explored) {
        /*// if All the nodes have been explored
        if (explored->size() == numNodes)
            return *output;*/

        // if current node have not been explored
        if (explored->count(v->value) == 0) {
            explored->insert(v->value);
            *output += std::to_string(v->value) + " ";

            // run dfs on all of its adjacent node recursively
            for (int i=0;i<v->numAdjacent;++i) {
                dfsUtil(v->adjacent_nodes[i], output, explored);
            }
        }
    }

    void Graph::bipartite() {
        if (numNodes == 0)
            return;
        std::set<int> explored;
        bool result = bipartiteUtil(&node_list[0], &explored);
        if (result)
            std::cout << "Graph is bipartite" << std::endl;
        else
            std::cout << "Graph is NOT bipartite" << std::endl;
    }

    bool Graph::bipartiteUtil(Node *v, std::set<int> *explored) {
        if (explored->count(v->value) != 0) {
            return true;
        }

        explored->insert(v->value);
        for (int i=0;i<v->numAdjacent;++i) {
            for (int j=i;j<v->numAdjacent;++j) {
                if (isConnected(v->adjacent_nodes[i], v->adjacent_nodes[j]))
                    return false;
            }
        }

        for (int k=0;k<v->numAdjacent;++k) {
            if(!bipartiteUtil(v->adjacent_nodes[k], explored)) {
                return false;
            }
        }

        return true;
    }

    bool Graph::isConnected(Node *u, Node *v) {
        for (int i=0;i<u->numAdjacent;++i) {
            if (u->adjacent_nodes[i]->value == v->value) {
                return true;
            }
        }
        return false;
    }

} // Graph