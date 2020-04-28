#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

#include "../sortData.h"

class QuickSort {
    private:
        sortData quickSortData;
        clock_t t;
        int comparisons;
        int movements;

        std::vector<int> keyVec;

        void qSort(int lowerBound, int upperBound) {
            int i = lowerBound;
            int j = upperBound;
            int pivot = keyVec[lowerBound + (upperBound - lowerBound) / 2];

            while (i <= j) {
                
                comparisons++;
                while (keyVec[i] < pivot) {
                    i++;
                    if (i > lowerBound) {
                        comparisons++;
                    }
                }
                comparisons++;
                while (keyVec[j] > pivot) {
                    j--;
                    if (j < upperBound) {
                        comparisons++;
                    }
                }

                if (i <= j) {
                    std::swap(keyVec[i], keyVec[j]);
                    movements++;
                    i++;
                    j--;
                }
            }

            if (lowerBound < j) {
                qSort(lowerBound, j);
            }
            if (i < upperBound) {
                qSort(i, upperBound);
            }
        }

    public:
        std::vector<int> sort(std::vector<int> toSort) {
            keyVec = toSort;
            qSort(0, toSort.size() - 1);
            return keyVec;
        }

        sortData sort(std::vector<int> toSort, std::string dataType) {
            t = clock();
            comparisons = 0;
            movements = 0;

            keyVec = toSort;
            qSort(0, toSort.size() - 1);
            t = clock() - t;

            quickSortData.sortedList = keyVec;
            quickSortData.n = toSort.size();
            quickSortData.dataType = dataType;
            quickSortData.sortType = "Quick";
            quickSortData.comparisons = comparisons;
            quickSortData.movements = movements;
            quickSortData.totalTime = t;            

            return quickSortData;
        }
};
#endif
