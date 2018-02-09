'''
input csv file (WIP)
process it into list

if list_size is < small num (10-20)
    insertion sort
else
    quick sort
'''

from sorts import insertionSort
from sorts import quickSort

inFileName = input("Give directory and filename for file you want to process: ")

inFile = open(inFileName, "r")

listToSort = []

for line in inFile:
    listToSort.append(int(line.rstrip()))


print(listToSort)

if len(listToSort) >= 15:
    print("quicksort")
    sortedList = quickSort.quickSort.qSortHelper(listToSort)
else:
    print("insertion sort")
    sortedList = insertionSort.insertionSort.iSort(listToSort)

print(sortedList)
