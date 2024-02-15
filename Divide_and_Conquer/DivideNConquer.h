//
// Created by wangj on 2024/2/15.
//

#ifndef INC_3105_ALGORITHMS_DIVIDENCONQUER_H
#define INC_3105_ALGORITHMS_DIVIDENCONQUER_H

#include "../Utility/MergeSort.h"
#include <iostream>

namespace DivideNConquer {
class DivideNConquer {
private:
    int sort_and_count(int *arr, int begin, int end);
    int merge_and_count(int *list, int left, int mid, int right);
public:
    void mergeSort(int *arr, int N);
    void countInversion(int *arr, int N);
};
} // DivideNConquer



#endif //INC_3105_ALGORITHMS_DIVIDENCONQUER_H
