//
// Created by wangj on 2024/2/1.
//

#ifndef INC_3105_ALGORITHMS_MERGESORT_H
#define INC_3105_ALGORITHMS_MERGESORT_H


template <typename T> class MergeSort {
private:
    static void mergeSortUtil(T* list, int begin, int end);
    static void merge(T* list, int left, int mid, int right);
public:
    static void merge_sort(T* list, int size);
};

template<typename T>
void MergeSort<T>::mergeSortUtil(T *list, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSortUtil(list, begin,mid);
    mergeSortUtil(list, mid+1, end);
    merge(list, begin, mid, end);
}

template<typename T>
void MergeSort<T>::merge(T *list, int left, int mid, int right) {
    int const left_size = mid - left + 1;
    int const right_size = right - mid;
    auto *leftList = new T[left_size], *rightList = new T[right_size];

    for (int i=0;i<left_size;++i) {
        leftList[i] = list[left + i];
    }
    for (int j=0;j<right_size;++j) {
        rightList[j] = list[mid + 1 + j];
    }

    auto indexLeft = 0, indexRight = 0;
    int indexMerged = left;

    while (indexLeft < left_size && indexRight < right_size) {
        if (leftList[indexLeft] < rightList[indexRight]) {
            list[indexMerged] = leftList[indexLeft];
            indexLeft++;
        } else {
            list[indexMerged] = rightList[indexRight];
            indexRight++;
        }
        indexMerged++;
    }

    while (indexLeft < left_size) {
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
}

template<typename T>
void MergeSort<T>::merge_sort(T *list, int size) {
    mergeSortUtil(list, 0, size-1);
}

#endif //INC_3105_ALGORITHMS_MERGESORT_H
