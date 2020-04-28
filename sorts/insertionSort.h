#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
//#include <time.h>

#include "../sortData.h"

class InsertionSort {
    private:
        sortData insertionSortData;
        clock_t t;
        int comparisons;
        int movements;

    public:
        std::vector<int> sort(std::vector<int> toSort) {
            for(int i = 0; i < toSort.size(); i++) {
                int temp = toSort[i];
                int j;
                for(j = i - 1; j >= 0 && temp < toSort[j]; j--) {
                    toSort[j + 1] = toSort[j];
                }
                toSort[j + 1] = temp;
            }
            return toSort;
        }

        sortData sort(std::vector<int> toSort, std::string dataType) {
            t = clock();
            comparisons = 0;
            movements = 0;

            for(int i = 0; i < toSort.size(); i++) {
                int key = toSort[i];
                int j = i - 1;
                while (j >= 0) {
                    comparisons++;
                    if (key < toSort[j]) {
                        movements++;
                        toSort[j + 1] = toSort[j];   
                        j--;
                    } else {
                        break;
                    }
                }
                toSort[j + 1] = key;
            }
            t = clock() - t;

            insertionSortData.sortedList = toSort;
            insertionSortData.n = toSort.size();
            insertionSortData.dataType = dataType;
            insertionSortData.sortType = "Insertion";
            insertionSortData.comparisons = comparisons;
            insertionSortData.movements = movements;
            insertionSortData.totalTime = t;

            return insertionSortData;
        }
};
#endif