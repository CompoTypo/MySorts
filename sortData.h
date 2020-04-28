#ifndef SORTDATA_H
#define SORTDATA_H

#include <vector>
#include <string>

struct sortData {
    std::vector<int> sortedList;
    int n;
    std::string dataType;
    std::string sortType;
    int comparisons;
    int movements;
    int totalTime;
};

#endif
