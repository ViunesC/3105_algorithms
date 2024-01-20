//
// Created by Re_Innocence on 2024/1/18.
//

#ifndef INC_3105_ALGORITHMS_DIRECTEDGRAPH_H
#define INC_3105_ALGORITHMS_DIRECTEDGRAPH_H

#include "Graph.h"

namespace DirectedGraph {

class DirectedGraph : public Graph::Graph {
private:
    DirectedGraph reverse();
public:
    DirectedGraph();
    ~DirectedGraph();
    void connectivity();
    void topoSort();
    };

} // DirectedGraph

#endif //INC_3105_ALGORITHMS_DIRECTEDGRAPH_H
