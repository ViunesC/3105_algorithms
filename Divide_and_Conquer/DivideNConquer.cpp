//
// Created by wangj on 2024/2/15.
//

#include "DivideNConquer.h"

namespace DivideNConquer {
    void DivideNConquer::mergeSort(int *arr, int N) {
        MergeSort<int>::merge_sort(arr, N);
    }

    void DivideNConquer::countInversion(int *arr, int N) {
        std::cout << sort_and_count(arr, 0, N-1) << std::endl;
    }

    int DivideNConquer::sort_and_count(int *arr, int begin, int end) {
        if (begin >= end)
            return 0;

        int mid = begin + (end - begin) / 2;
        int r1 = sort_and_count(arr, begin, mid);
        int r2 = sort_and_count(arr, mid+1, end);
        int r3 = merge_and_count(arr, begin, mid, end);

        return r1+r2+r3;
    }

    int DivideNConquer::merge_and_count(int *list, int left, int mid, int right) {
        int const left_size = mid - left + 1;
        int const right_size = right - mid;
        auto *leftList = new int[left_size], *rightList = new int[right_size];

        for (int i=0;i<left_size;++i) {
            leftList[i] = list[left + i];
        }
        for (int j=0;j<right_size;++j) {
            rightList[j] = list[mid + 1 + j];
        }

        auto indexLeft = 0, indexRight = 0;
        int indexMerged = left;
        int numInverted = 0;

        while (indexLeft < left_size && indexRight < right_size) {
            if (leftList[indexLeft] < rightList[indexRight]) {
                list[indexMerged] = leftList[indexLeft];
                indexLeft++;
            } else {
                numInverted += left_size - indexLeft;
                list[indexMerged] = rightList[indexRight];
                indexRight++;
            }
            indexMerged++;
        }

        while (indexLeft < left_size) {
            numInverted += right_size;
            list[indexMerged] = leftList[indexLeft];
            indexLeft++;
            indexMerged++;
        }

        while (indexRight < right_size) {
            list[indexMerged] = rightList[indexRight];
            indexRight++;
            indexMerged++;
        }

        delete[] leftList;
        delete[] rightList;

        return numInverted;
    }

} // DivideNConquer