//
// Created by Re_Innocence on 2024/1/20.
//

#ifndef INC_3105_ALGORITHMS_GREEDY_H
#define INC_3105_ALGORITHMS_GREEDY_H

#define MODE_STARTING_TIME 0
#define MODE_FINISHING_TIME 1

#include <iostream>
#include <vector>

struct Interval {
private:
    std::string name;
    int start;
    int timeTaken;
    int weight;
public:
    Interval();
    Interval(std::string name, int start, int timeTaken);
    Interval(std::string name, int start, int timeTaken, int weight);
    std::string getName();
    int getStartTime();
    int getTimeTaken();
    int getFinishTime();
    int getWeight();
    bool isCompatible(Interval *i);
};

namespace Greedy {

class Greedy {
private:
    void mergeSortUtil(Interval* list, int begin, int end, int MODE);
    void merge(Interval* list, int left, int mid, int right, int MODE);
    static int compare(Interval *a, Interval *b, int MODE);
public:
    Greedy() = default;
    ~Greedy() = default;
    void merge_sort(Interval* list, int size, int MODE);
    void find_maxSubset(Interval* list, int size);
    void find_minRoomReq(Interval* list, int size);
};

} // Greedy

#endif //INC_3105_ALGORITHMS_GREEDY_H
