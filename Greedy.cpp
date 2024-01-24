//
// Created by Re_Innocence on 2024/1/20.
//

#include "Greedy.h"

namespace Greedy {
    int Greedy::compare(Interval *a, Interval *b, int MODE) {
        // Compare a and b by either earliest-start-time or earliest-finish-time
        // return 1 if a is earlier than b, and 0 if vice versa

        if (MODE == MODE_STARTING_TIME) {
            if (a->getStartTime() < b->getStartTime())
                return 1;
            else
                return 0;
        } else if (MODE == MODE_FINISHING_TIME) {
            if (a->getFinishTime() < b->getFinishTime())
                return 1;
            else
                return 0;
        }

        std::cout << "Unknown mode. Try again." << std::endl;
        return -1;
    }

    void Greedy::merge_sort(Interval *list, int size, int MODE) {
        mergeSortUtil(list, 0, size-1, MODE);
    }

    void Greedy::find_maxSubset(Interval *list, int size) {
        if (size == 0)
            return;

        // Sort list by earliest-finishing-time
        merge_sort(list, size, 1);
        int numIntervals = 0;
        std::string output;
        Interval *p;

        numIntervals++;
        p = &list[0];
        output += p->getName() + " ";
        for (int i=1;i<size;++i) {
            if (p->isCompatible(&list[i])) {
                numIntervals++;
                output += list[i].getName() + " ";
                p = &list[i];
            }
        }
        std::cout << "The maximum number of compatible jobs is: " << numIntervals << std::endl;
        std::cout << "They are: " << output << std::endl;
    }

    void Greedy::find_minRoomReq(Interval *list, int size) {
        if (size == 0)
            return;

        // Sort list by earliest-starting-time
        merge_sort(list, size, 0);
        /*for (int i=0;i<size;++i) {
            std::cout << list[i].getName() << " ";
        }
        std::cout << std::endl;*/
        std::vector<std::vector<Interval*>> roomList;
        int numRooms = 0;
        Interval *p;
        bool isFitted;

        numRooms++;
        std::vector<Interval*> r1;
        r1.push_back(&list[0]);
        roomList.push_back(r1);
        for (int i=1;i<size;++i) {
            isFitted = false;
            p = &list[i];
            for (auto &it : roomList) {
                if (!it.empty()) {
                    if (it.back()->isCompatible(p)) {
                        isFitted = true;
                        it.push_back(p);
                        break;
                    }
                }
            }

            if (!isFitted) {
                std::vector<Interval*> new_room;
                new_room.push_back(p);
                roomList.push_back(new_room);
                numRooms++;
            }
        }

        std::cout << "The number of rooms required to handle all jobs is: " << numRooms << std::endl;

        int number = 1;
        for (auto &it : roomList) {
            std::cout << "Room " << number << ": ";
            for (auto &it1 : it) {
                std::cout << it1->getName() << " ";
            }
            ++number;
            std::cout << std::endl;
        }
    }

    void Greedy::mergeSortUtil(Interval *list, int begin, int end, int MODE) {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        mergeSortUtil(list, begin,mid, MODE);
        mergeSortUtil(list, mid+1, end, MODE);
        merge(list, begin, mid, end, MODE);
    }

    void Greedy::merge(Interval *list, int left, int mid, int right, int MODE) {
        int const left_size = mid - left + 1;
        int const right_size = right - mid;
        auto *leftList = new Interval[left_size], *rightList = new Interval[right_size];

        for (int i=0;i<left_size;++i) {
            leftList[i] = list[left + i];
        }
        for (int j=0;j<right_size;++j) {
            rightList[j] = list[mid + 1 + j];
        }

        auto indexLeft = 0, indexRight = 0;
        int indexMerged = left;

        while (indexLeft < left_size && indexRight < right_size) {
            if (compare(&leftList[indexLeft], &rightList[indexRight], MODE)) {
                // std::cout << leftList[indexLeft].getName() << " is earlier than " << rightList[indexRight].getName() << std::endl;
                list[indexMerged] = leftList[indexLeft];
                indexLeft++;
            } else {
                // std::cout << rightList[indexRight].getName() << " is earlier than " << leftList[indexLeft].getName() << std::endl;
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
} // Greedy

int Interval::getStartTime() {
    return this->start;
}

int Interval::getTimeTaken() {
    return this->timeTaken;
}

int Interval::getFinishTime() {
    return this->start + this->timeTaken;
}

int Interval::getWeight() {
    return this->weight;
}

Interval::Interval(std::string name, int start, int timeTaken) {
    this->start = start;
    this->timeTaken = timeTaken;
    this->weight = 0;
    this->name = name;
}

Interval::Interval(std::string name, int start, int timeTaken, int weight) {
    this->start = start;
    this->timeTaken = timeTaken;
    this->weight = weight;
    this->name = name;
}

Interval::Interval() {
    this->start = 0;
    this->timeTaken = 0;
    this->weight = 0;
    this->name = "";
}

std::string Interval::getName() {
    return this->name;
}

bool Interval::isCompatible(Interval *i) {
    if (this->getFinishTime() <= i->getStartTime() || i->getFinishTime() <= this->getStartTime())
        return true;
    else
        return false;
}
