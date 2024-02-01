cmake_minimum_required(VERSION 3.27)
project(3105_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(3105_algorithms main.cpp
        StableMatching/stableMatching.cpp
        StableMatching/stableMatching.h
        Graph/Graph.cpp
        Graph/Graph.h
        DirectedGraph/DirectedGraph.cpp
        DirectedGraph/DirectedGraph.h
        Greedy/Greedy.cpp
        Greedy/Greedy.h
        WeightedGraph/WeightedGraph.cpp
        WeightedGraph/WeightedGraph.h
        Utility/MergeSort.h)
