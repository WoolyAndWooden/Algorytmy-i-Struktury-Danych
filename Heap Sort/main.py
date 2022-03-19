#Below is implementation of Heap sort, both recursively and iteratively

#recursive
def heapify(A, i, heapSize):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < heapSize and A[l] > A[i]:
        largest = l

    if r < heapSize and A[r] > A[largest]:
        largest = r

    if largest != i:
        temp = A[i]
        A[i] = A[largest]
        A[largest] = temp

        heapify(A, largest, heapSize)


def buildHeap(A):
    heapSize = len(A)
    for i in range(heapSize // 2 -1, -1, -1):
        heapify(A, i, heapSize)


def heapSort(A):
    heapSize = len(A)
    buildHeap(A)


    for i in range(heapSize-1, 0, -1):
        temp = A[i]
        A[i] = A[0]
        A[0] = temp
        heapify(A, 0, i)


#iterative
def iBuildHeap(A, heapSize):
    for i in range(heapSize):
        if A[i] > A[int((i-1) / 2)]:
            j = i

            while A[j] > A[int((j - 1) / 2)]:
                temp = A[j]
                A[j] = A[int((j - 1) / 2)]
                A[int((j - 1) / 2)] = temp

                j = int((j-1)/2)


def iHeapSort(A, heapSize):
    iBuildHeap(A, heapSize)

    for i in range(heapSize-1, 0, -1):
        temp = A[0]
        A[0] = A[i]
        A[i] = temp

        bigChild = -1
        j = 0
        while bigChild < i:

            bigChild = 2*j+1

            if bigChild < i-1 and A[bigChild] < A[bigChild+1]:
                bigChild+=1

            if bigChild < i and A[j] < A[bigChild]:
                temp = A[j]
                A[j] = A[bigChild]
                A[bigChild] = temp

            j = bigChild


file = open("tosort.txt")

arr = []

for line in file:
    arr.append(int(line))
print(arr)
heapSort(arr)
print(arr)

file.close()

file = open("sorted.txt", "w")

for i in arr:
    file.write(str(i))
    file.write("\n")

file.close()

file = open("tosort.txt")

arr = []

for line in file:
    arr.append(int(line))
print(arr)
iHeapSort(arr, len(arr))
print(arr)

file.close()

file = open("isorted.txt", "w")

for i in arr:
    file.write(str(i))
    file.write("\n")

file.close()





