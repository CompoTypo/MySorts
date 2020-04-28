#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>

#include "../sortData.h"

class HeapSort {
    private:
        sortData heapSortData;
        clock_t t;
        int comparisons;
        int movements;

        void heapify(std::vector<int> &vec, int index, int size) {                
            int largest = index;
            int left = (2 * index) + 1;
            int right = (2 * index) + 2;
            
            if(left < size) {
                comparisons++;
                if (vec[left] > vec[index]) {
                    largest = left;
                }                
            }

            if(right < size) {
                comparisons++;
                if (vec[right] > vec[largest]) {
                    largest = right;
                }            
            }

            if(largest != index) {
                std::swap(vec[largest], vec[index]);
                movements++;
                heapify(vec, largest, size);
            }
        }
    public:
        sortData sort(std::vector<int> vec, std::string dataType) {
            t = clock();
            comparisons = 0;
            movements = 0;

            for(int i = vec.size() / 2 - 1; i >= 0; i--) {
                heapify(vec, i, vec.size());
            }
            
            int end = vec.size() - 1;
            while (end > 0) {
                std::swap(vec[0], vec[end]);
                movements++;
                heapify(vec, 0, end);
                --end;
            }
            t = clock() - t;

            heapSortData.sortedList = vec;
            heapSortData.n = vec.size();
            heapSortData.dataType = dataType;
            heapSortData.sortType = "Heap";
            heapSortData.comparisons = comparisons;
            heapSortData.movements = movements;
            heapSortData.totalTime = t;

            return heapSortData;
        }
};
#endif