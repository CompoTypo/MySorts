#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>

#include "../sortData.h"

class RadixSort {
    private:
        sortData radixSortData;
        clock_t t;
        int comparisons;
        int movements;

        std::vector<int> output;

        int getMax(std::vector<int> vec) { 
            int max = vec[0]; 
            for (int i = 1; i < vec.size(); i++) 
                if (vec[i] > max) 
                    max = vec[i]; 
            return max; 
        }

        std::vector<int> radix(std::vector<int> unSorted, int digitPlace) {
            output.reserve(unSorted.size());
            int i, count[10] = {0}; 

            for (i = 0; i < unSorted.size(); i++) { 
                count[(unSorted[i] / digitPlace) % 10]++; 
            }

            for (i = 1; i < 10; i++) {
                count[i] += count[i - 1]; 
            }

            for (i = unSorted.size() - 1; i >= 0; i--) { 
                output[count[(unSorted[i] / digitPlace) % 10] - 1] = unSorted[i]; 
                count[(unSorted[i] / digitPlace) % 10]--; 
            } 

            for (i = 0; i < unSorted.size(); i++) {
                movements++;
                unSorted[i] = output[i]; 
            }
            return unSorted;
        }
    public:
        std::vector<int> sort(std::vector<int> toSort) {
            int max = getMax(toSort); 

            for (int digitPlace = 1; max/digitPlace > 0; digitPlace *= 10) {
                toSort = radix(toSort, digitPlace);
            }       
            return toSort;  
        }

        sortData sort(std::vector<int> toSort, std::string dataType) {
            t = clock();
            comparisons = 0;
            movements = 0;

            int max = getMax(toSort); 

            for (int digitPlace = 1; max/digitPlace > 0; digitPlace *= 10) {
                toSort = radix(toSort, digitPlace);
            }       
            t = clock() - t;

            radixSortData.sortedList = toSort;
            radixSortData.n = toSort.size();
            radixSortData.dataType = dataType;
            radixSortData.sortType = "Radix";
            radixSortData.comparisons = comparisons;
            radixSortData.movements = movements;
            radixSortData.totalTime = t;

            return radixSortData;  
        }
};

#endif
