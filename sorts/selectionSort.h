#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>

#include "../sortData.h"

class SelectionSort {
    private:
        sortData selectionSortData;
        clock_t t;
        int comparisons;
        int movements;
    public:
        sortData sort(std::vector<int> toSort, std::string dataType) {
            t = clock();
            comparisons = 0;
            movements = 0;
            
            for(int i = 0; i < toSort.size() - 1; i++) {
                int index = i;
                for(int j = i + 1; j < toSort.size(); j++) {
                    comparisons++;
                    if (toSort[j] < toSort[index]) {
                        index = j;
                    } 
                }
                movements++;
                std::swap(toSort[index], toSort[i]);
            }
            t = clock() - t;

            selectionSortData.sortedList = toSort;
            selectionSortData.n = toSort.size();
            selectionSortData.dataType = dataType;
            selectionSortData.sortType = "Selection";
            selectionSortData.comparisons = comparisons;
            selectionSortData.movements = movements;
            selectionSortData.totalTime = t;

            return selectionSortData;
        }
};
#endif