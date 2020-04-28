#ifndef LISTGENERATION_H
#define LISTGENERATION_H

#include <ctime>
#include <cstdlib>

#include "sorts/insertionSort.h"
#include "sorts/quickSort.h"
#include "sorts/radixSort.h"

class ListGeneration {
    private:
        std::vector<int> output;

        std::vector<int> generateInOrder(int n) {
            std::vector<int> tempVec = generateRandom(n);
            if (n <= 20) {
                InsertionSort insertion;
                tempVec = insertion.sort(tempVec);
            } else if (n > 20 && n <= 15000) {
                QuickSort quick;
                tempVec = quick.sort(tempVec);
            } else if (n > 15000) {
                RadixSort radix;
                tempVec = radix.sort(tempVec);
            }
            return tempVec;
        }

        std::vector<int> generateReverseOrder(int n) {
            std::vector<int> tempVec = generateInOrder(n);
            std::vector<int> tempVec2;
            for (int i = tempVec.size() - 1; i >= 0; i--) {
                tempVec2.push_back(tempVec[i]);
            }
            return tempVec2;
        }

        // essentially its a randomized swap function
        std::vector<int> generateAlmostOrder(int n) {
            std::vector<int> tempVec = generateInOrder(n);
            int constraint;
            if (tempVec.size() < 10) {
                constraint = 1;
            } else if (tempVec.size() >= 10 && tempVec.size() < 20) {
                constraint = 2;
            } else {
                constraint = tempVec.size() / 20;
            }
            
            for (int j = 0; j < constraint; j++) {
                int temp;
                int a = rand() % tempVec.size();
                int b = rand() % tempVec.size();
                temp = tempVec[a];
                tempVec[a] = tempVec[b];
                tempVec[b] = temp;
            }
            return tempVec;
        }

        std::vector<int> generateRandom(int n) {
            std::vector<int> tempVec;
            for(int i = 0; i < n; i++) {
                tempVec.push_back(rand());
            }
            return tempVec;
        }

    public:
        std::vector<int> generate(std::string listStyle, int n) {
            srand(time(NULL));
            if (listStyle == "InOrder") {
                output = generateInOrder(n);
            } else if (listStyle == "ReverseOrder") {
                output = generateReverseOrder(n);
            } else if (listStyle == "AlmostOrder") {
                output = generateAlmostOrder(n);
            } else if (listStyle == "Random") {
                output = generateRandom(n);
            }
            return output;
        }
};
#endif