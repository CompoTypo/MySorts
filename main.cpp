#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "listGeneration.h"
#include "sortData.h"

#include "sorts/insertionSort.h"
#include "sorts/selectionSort.h"
#include "sorts/mergeSort.h"
#include "sorts/quickSort.h"
#include "sorts/heapSort.h"
#include "sorts/radixSort.h"

using namespace std;

int main() {
    vector<int> toSort;
    ListGeneration generator;
    int numItems = 20000;

    sortData sortedData;
    std::vector<sortData> results;


    string listOfSorts[] = {"Selection", "Insertion", "Merge", "Quick", "Heap", "Radix"};
    string listOfListGenerations[] = {"InOrder", "ReverseOrder", "AlmostOrder", "Random"};

    cout << "Enter number of items you would like to sort: ";
    cin >> numItems;

    for (int listType = 0; listType < sizeof(listOfListGenerations) / sizeof(*listOfListGenerations); listType++) {
        
        toSort = generator.generate(listOfListGenerations[listType], numItems); 
        
        for (int sortType = 0; sortType < sizeof(listOfSorts) / sizeof(*listOfSorts); sortType++) {
            switch (sortType) {
                case 0: 
                    {
                        SelectionSort selection;
                        sortedData = selection.sort(toSort, listOfListGenerations[listType]);
                        break;
                    }
                case 1: 
                    {
                        InsertionSort insertion;
                        sortedData = insertion.sort(toSort, listOfListGenerations[listType]);
                        break;
                    }
                case 2:
                    {    
                        MergeSort merge;
                        sortedData = merge.sort(toSort, listOfListGenerations[listType]);
                        break;
                    }
                case 3:
                    {    
                        QuickSort quick;
                        sortedData = quick.sort(toSort, listOfListGenerations[listType]);
                        break;
                    }
                case 4:
                    {
                        HeapSort heap;
                        sortedData = heap.sort(toSort, listOfListGenerations[listType]);
                        break;
                    }
                case 5:
                    {
                        RadixSort radix;
                        sortedData = radix.sort(toSort, listOfListGenerations[listType]);
                        break;
                    }
                default:
                    break;
            }
            cout << "Sort of " << listOfListGenerations[listType] << " data with " << listOfSorts[sortType] << " sort." << endl;
            for(int i = 0; i < sortedData.sortedList.size(); i++) {
                cout << sortedData.sortedList[i] << endl;
            }
            cout << endl;
            results.push_back(sortedData);
        }  
    }  
    cout << setw(15) << left << "Sort type" << setw(15) << left << "# of Elements" << setw(15) << left << "Data type" << setw(15) << left << "Comparisons" << setw(15) << left << "Movements" << setw(15) << left << "Totaltime" << endl;
       
    for (int i = 0; i < results.size(); i++) {
        if (results[i].sortType == "Insertion") {
            cout << setw(15) << left << results[i].sortType << setw(15) << left << results[i].n << setw(15) << left << results[i].dataType << setw(15) << left << results[i].comparisons << setw(15) << left << results[i].movements << setw(15) << left << results[i].totalTime << endl;
            
        }
    }
    for (int i = 0; i < results.size(); i++) {
        if (results[i].sortType == "Selection") {
            cout << setw(15) << left << results[i].sortType << setw(15) << left << results[i].n << setw(15) << left << results[i].dataType << setw(15) << left << results[i].comparisons << setw(15) << left << results[i].movements << setw(15) << left << results[i].totalTime << endl;
        }
    }
    for (int i = 0; i < results.size(); i++) {
        if (results[i].sortType == "Merge") {
            cout << setw(15) << left << results[i].sortType << setw(15) << left << results[i].n << setw(15) << left << results[i].dataType << setw(15) << left << results[i].comparisons << setw(15) << left << results[i].movements << setw(15) << left << results[i].totalTime << endl;
        }
    }
    for (int i = 0; i < results.size(); i++) {
        if (results[i].sortType == "Quick") {
            cout << setw(15) << left << results[i].sortType << setw(15) << left << results[i].n << setw(15) << left << results[i].dataType << setw(15) << left << results[i].comparisons << setw(15) << left << results[i].movements << setw(15) << left << results[i].totalTime << endl;
        }
    }
    for (int i = 0; i < results.size(); i++) {
        if (results[i].sortType == "Heap") {
            cout << setw(15) << left << results[i].sortType << setw(15) << left << results[i].n << setw(15) << left << results[i].dataType << setw(15) << left << results[i].comparisons << setw(15) << left << results[i].movements << setw(15) << left << results[i].totalTime << endl;
        }
    }
    for (int i = 0; i < results.size(); i++) {
        if (results[i].sortType == "Radix") {
            cout << setw(15) << left << results[i].sortType << setw(15) << left << results[i].n << setw(15) << left << results[i].dataType << setw(15) << left << results[i].comparisons << setw(15) << left << results[i].movements << setw(15) << left << results[i].totalTime << endl;
        }
    }
}