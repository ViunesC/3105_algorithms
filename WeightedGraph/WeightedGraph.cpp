//
// Created by Re_Innocence on 2024/1/20.
//

#include "WeightedGraph.h"

namespace WeightedGraph {

    int Edge::getVertexConnected() {
        return toVertex;
    }

    int Edge::getWeight() {
        return weight;
    }

    Edge::Edge(int v, int weight) {
        this->toVertex = v;
        this->weight = weight;
    }

    int Vertex::getValue() {
        return value;
    }

    std::vector<Edge> *Vertex::getEdges() {
        return &this->edgeList;
    }

    Vertex::Vertex(int value) {
        this->value = value;
    }

    size_t Vertex::getNumConnected() {
        return edgeList.size();
    }

    bool Vertex::isConnected(int v) {
        for (Edge e : edgeList)
            if (e.getVertexConnected() == v)
                return true;
        return false;
    }

    void Vertex::addEdge(int v, int weight) {
        Edge e(v, weight);
        edgeList.push_back(e);
    }

    void Vertex::removeEdge(int v) {
        for (auto it=edgeList.begin();it != edgeList.end();++it) {
            if (it->getVertexConnected() == v) {
                edgeList.erase(it);
                return;
            }
        }
        std::cout << "Cannot remove the edge" << std::endl;
    }

    Edge* Vertex::getEdge(int v) {
        for (auto &it : edgeList) {
            if (it.getVertexConnected() == v)
                return &it;
        }

        std::cout << "Cannot find edge to " << v << std::endl;
        return nullptr;
    }

    WeightedGraph::WeightedGraph() = default;

    void WeightedGraph::addVertex(int value) {
        if (isExist(value)) {
            std::cout << "Vertex already existed" << std::endl;
            return;
        }

        Vertex v(value);
        adjacencyList.push_back(v);
    }

    void WeightedGraph::removeVertex(int value) {
        if (getN() == 0 || !isExist(value))
            return;
        for (Vertex v : adjacencyList) {
            if (v.isConnected(value))
                removeEdge(value, v.getValue());
        }

        for (auto it=adjacencyList.begin();it != adjacencyList.end();++it) {
            if (it->getValue() == value) {
                adjacencyList.erase(it);
                break;
            }
        }
    }

    void WeightedGraph::addEdge(int u, int v, int weight) {
        if (u == v)
            return;

        int u_pos = find(u);
        int v_pos = find(v);
        // std::cout << v_pos << std::endl;
        if (u_pos == -1 || v_pos == -1) {
            std::cout << "Vertex " << u << " or " << v << " does not exist" << std::endl;
            return;
        }
        if (adjacencyList[u_pos].isConnected(v)) {
            std::cout << "Edge already existed" << std::endl;
            return;
        }
        adjacencyList[u_pos].addEdge(v, weight);
        adjacencyList[v_pos].addEdge(u, weight);
    }

    void WeightedGraph::removeEdge(int u, int v) {
        int u_pos = find(u);
        int v_pos = find(v);
        if (u_pos == -1 || v_pos == -1) {
            std::cout << "Vertex " << u << " or " << v << " does not exist" << std::endl;
            return;
        }
        if (!adjacencyList[u_pos].isConnected(v)) {
            std::cout << "Two vertices are not connected" << std::endl;
            return;
        }
        adjacencyList[u_pos].removeEdge(v);
        adjacencyList[v_pos].removeEdge(u);
    }

    size_t WeightedGraph::getN() {
        return adjacencyList.size();
    }

    void WeightedGraph::shortest_path(int u) {
        std::priority_queue<myPair, std::vector<myPair>, std::greater<myPair>> pq;
        std::vector<int> dist(this->getN(), INF_DIST);

        int src = find(u);
        if (src == -1)
            return;
        pq.push(std::make_pair(0, &adjacencyList[src]));
        dist[src] = 0;
        int v, weight, t;
        Vertex* p;

        while (!pq.empty()) {
            p = pq.top().second;
            pq.pop();
            t = find(p->getValue());

            // 'i' is used to get all adjacent vertices of a
            // vertex
            for (Edge it : *p->getEdges()) {
                // Get vertex label and weight of current
                // adjacent of u.
                v = find(it.getVertexConnected());
                weight = it.getWeight();

                // If there is shorted path to v through u.
                if (dist[v] > dist[t] + weight) {
                    // std::cout << "distance from " << u << " to " << v << " is " << dist[v];
                    // std::cout << ", updated to " << dist[src] + weight << std::endl;
                    // Updating distance of v
                    dist[v] = dist[t] + weight;
                    pq.push(std::make_pair(dist[v], &adjacencyList[v]));
                }
            }
        }

        printf("Vertex Distance from Source\n");
        for (int i = 0; i < getN(); ++i)
            printf("%d \t\t %d\n", adjacencyList[i].getValue(), dist[i]);
    }

    bool WeightedGraph::isExist(int value) {
        for (Vertex v : adjacencyList) {
            if (v.getValue() == value)
                return true;
        }
        return false;
    }

    int WeightedGraph::find(int value) {
        for (int i=0;i<getN();++i) {
            if (adjacencyList[i].getValue() == value)
                return i;
        }
        std::cout << "Cannot find vertex " << value << std::endl;
        return -1;
    }

    void WeightedGraph::printAll() {
        for (Vertex v : adjacencyList) {
            std::cout << v.getValue() << ": ";
            for (Edge e : *v.getEdges())
                std::cout << e.getVertexConnected() << "[" << e.getWeight() << "] ";
            std::cout << std::endl;
        }
    }

    void WeightedGraph::primMST(int u) {
        // TODO: Find a better way to display result
        std::vector<int> explored;
        std::vector<int> mst;

        std::priority_queue<myPair, std::vector<myPair>, std::greater<myPair>> pq;

        int src = find(u);   // O(n)
        if (src == -1)
            return;
        pq.push(std::make_pair(0, &adjacencyList[src]));
        int p_val, tree_len = 0, edge;
        bool isExplored;
        Vertex* p;


        while (explored.size() != getN()) {   // O(n)
            if (pq.empty())
                break;

            edge = pq.top().first;
            p = pq.top().second;
            pq.pop();   // O(nlogn)
            p_val = p->getValue();

            isExplored = false;
            for (int x : explored) {   // O(n)
                if (x == p_val) {
                    isExplored = true;
                    break;
                }
            }

            if (!isExplored) {
                // std::cout << "Explore " << p_val << std::endl;
                explored.push_back(p_val);
                tree_len += edge;
                if (p_val != u) {
                    mst.push_back(edge);
                }

                // Push all of its adjacent edge(vertice) into PQ
                for (Edge it : *p->getEdges()) {   // O(|E(n)|)
                    pq.push(std::make_pair(it.getWeight(), &adjacencyList[find(it.getVertexConnected())]));  // O(nlogn)
                }
            }
        }

        while (!pq.empty())   // O(nlogn)
            pq.pop();

        std::cout << "Total length of Spanning tree is " << tree_len << std::endl;
        std::string str;
        for (int v : explored) {
            str += std::to_string(v) + "->";
        }
        str.erase(str.size()-2, 2);

        std::cout << str << std::endl;

        if (explored.size() < getN()) {
            std::cout << "Graph is disconnected. Output MST is not complete." << std::endl;
        }
    }

    Edge* WeightedGraph::getEdge(int u, int v) {
        int u_pos = find(u);
        if (u_pos == -1) {
            std::cout << "Cannot find vertex " << u << std::endl;
            return nullptr;
        }

        return adjacencyList[u_pos].getEdge(v);
    }
} // WeightedGraph