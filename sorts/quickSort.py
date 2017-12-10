'''
    Always pick first element as pivot.
    Always pick last element as pivot (implemented below)
    Pick a random element as pivot.
    Pick median as pivot.
'''
class quickSort:
    def partition(arr, low, high):
        pivot = arr[high]

        i = low - 1

        for j in range(low, high):
            if arr[j] <= pivot:
                i+=1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    # low  --> Starting index,  high  --> Ending index
    def qSort(arr, low, high):
        if low < high:
            partIndex = quickSort.partition(arr, low, high)

            quickSort.qSort(arr, low, partIndex-1)
            quickSort.qSort(arr, partIndex+1, high)

            return arr

    def qSortHelper(arr):
        low = 0
        high = len(arr) - 1

        sorted = quickSort.qSort(arr, low, high)
        return sorted




