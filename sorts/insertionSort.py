
# start with a list of unsorted ints
# add first index of list to new list
# go through each index
# cascade it down til it fits between larger and smaller


class insertionSort:

    def iSort(toSort):
        for i in range(1, len(toSort)):
            actor = toSort[i]
            j = i - 1
            while j >= 0 and actor < toSort[j]:
                toSort[j + 1] = toSort[j]
                j -= 1
            toSort[j + 1] = actor
        return toSort

