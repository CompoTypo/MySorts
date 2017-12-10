
class bubbleSort:
    def bubSort(list):
        for j in range(0, len(list)):
            for i in range(j, len(list)):
                if list[j] > list[i]:
                    list[j], list[i] = list[i], list[j] # swap function

        return list
