#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

#include "../sortData.h"

class MergeSort {
    private:
        sortData mergeSortData;
        clock_t t;
        int comparisons;
        int movements;

        std::vector<int> keyVec;
        std::vector<int> tempVec;
    
        void mergeTogether(int lowerBound, int middle, int upperBound) {
            for (int i = lowerBound; i <= upperBound; i++) {
                tempVec[i] = keyVec[i];
            }

            int i = lowerBound;
            int j = middle + 1;
            int k = lowerBound;
            comparisons++;
            while(i <= middle && j <= upperBound) {
                comparisons++;
                if (tempVec[i] <= tempVec[j]) {
                    keyVec[k] = tempVec[i];
                    i++;
                } else {
                    keyVec[k] = tempVec[j];
                    j++;                   
                }
                k++;
            }

            while(i <= middle) {
                comparisons++;
                movements++;
                keyVec[k] = tempVec[i];
                k++;
                i++;
            }
            tempVec.pop_back(); 
        }

        void breakDown(int lowerBound, int upperBound) {
            if (lowerBound < upperBound) {
                int middle = lowerBound + (upperBound - lowerBound) / 2;
                breakDown(lowerBound, middle);
                breakDown(middle + 1, upperBound);
                mergeTogether(lowerBound, middle, upperBound);
            }  
        }

    public:
        sortData sort(std::vector<int> toSort, std::string dataType) {
            t = clock();
            comparisons = 0;
            movements = 0;

            keyVec = toSort;
            tempVec.reserve(keyVec.size());
            breakDown(0, toSort.size() - 1);
            t = clock() - t;

            mergeSortData.sortedList = keyVec;
            mergeSortData.n = keyVec.size();
            mergeSortData.dataType = dataType;
            mergeSortData.sortType = "Merge";
            mergeSortData.comparisons = comparisons;
            mergeSortData.movements = movements;
            mergeSortData.totalTime = t;

            return mergeSortData;
        }    
};
#endif
