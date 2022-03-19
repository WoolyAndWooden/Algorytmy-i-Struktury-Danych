#In this file is recursive (b) and iterative implementation of quicksort algorithm

import random as rand
from timeit import default_timer as timer
import sys
sys.setrecursionlimit(10000)

def partitionb(arr, l, h):
    p = arr[h]

    i = l - 1

    for j in range(l, h):
        if arr[j] <= p:
            i+=1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[h] = arr[h], arr[i + 1]
    return i + 1


def quicksortb(arr, l, h, c):
    if l + c < h:
        p = partitionb(arr, l, h)
        quicksortb(arr, l, p - 1, c)
        quicksortb(arr, p + 1, h, c)
    else:
        for i in range(l, h):
            for j in range(l, h):
                if arr[j] > arr[i + 1]:
                    arr[j], arr[i + 1] = arr[i + 1], arr[j]

def partition(arr, l, h):
    p = arr[h]

    i = l - 1

    for j in range(l, h):
        if arr[j] <= p:
            i+=1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[h] = arr[h], arr[i + 1]
    return i + 1


def quicksort(arr, l, h):
    if l < h:
        p = partition(arr, l, h)
        quicksort(arr, l, p - 1)
        quicksort(arr, p + 1, h)

arr = [10, 7, 8, 9, 1, 5]
print(arr)

quicksort(arr, 0, len(arr) - 1)
print(arr)

arr = [10, 7, 8, 9, 1, 5]
print(arr)

quicksortb(arr, 0, len(arr) - 1, 2)
print(arr)

arrrand = []
for i in range(0, 10000):
    arrrand.append(rand.randint(0, 100000))

arrrandb = arrrand.copy()
start = timer()
quicksort(arrrand, 0, len(arrrand) - 1)
end = timer()

if max(arrrand) == arrrand[len(arrrand) - 1]:
    print(end - start)

start = timer()
quicksortb(arrrandb, 0, len(arrrandb) - 1, 1000)
end = timer()
if max(arrrandb) == arrrand[len(arrrandb) - 1]:
    print(end - start)


arrranddesc = []
for i in range(2990, 0, -1): #Ciąg malejący dłuższy niż 2900 to za dużo dla pythona
    arrranddesc.append(i)

arrranddescb = arrranddesc.copy()

start = timer()
quicksort(arrranddesc, 0, len(arrranddesc) - 1)
end = timer()
if max(arrranddesc) == arrranddesc[len(arrranddesc) - 1]:
    print(end - start)

start = timer()
quicksortb(arrranddescb, 0, len(arrranddescb) - 1, 1000)
end = timer()
if max(arrranddescb) == arrranddescb[len(arrranddescb) - 1]:
    print(end - start)