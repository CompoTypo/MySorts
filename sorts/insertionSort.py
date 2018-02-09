
# start with a list of unsorted ints
# add first index of list to new list
# go through each index
# cascade it down til it fits between larger and smaller


class insertionSort:

    def iSort(toSort):
        for i in range(1 , len(toSort)):
            actor = toSort[i]
            j = i
            while j > 0 and actor < toSort[j - 1]:
                toSort[j] = toSort[j - 1]
                j -= 1
            toSort[j] = actor
            print(toSort)
        return toSort

