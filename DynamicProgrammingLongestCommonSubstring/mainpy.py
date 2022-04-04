from operator import truediv
import numpy as np
from colorama import Back, Style
import os


clear = lambda : os.system('cls')


def LCS(X, Y, m, n):
    C = np.zeros((m+1, n+1))

    for i in range(0, m):
        for j in range(0, n):
            if X[i] == Y[j]:
                C[i+1][j+1] = C[i][j] + 1
            else:
                C[i+1][j+1] = max(C[i+1][j], C[i][j+1])
    print(C)
    return LCSLookup(X, Y, C)


def LCSLookup(X, Y, C):
    D = np.zeros((np.shape(C)))
    i = np.shape(C)[0]-1
    j = np.shape(C)[1]-1
    D[i][j] = 1
    Z = [X[i-1]]
    while C[i][j] != 0:
        if C[i-1][j] == C[i][j]:
            i = i - 1
            D[i][j] = 1
        elif C[i][j-1] == C[i][j]:
            j = j - 1
            D[i][j] = 1
        else:
            i = i - 1
            j = j - 1
            D[i][j] = 1
            Z.append(X[i-1])
    LCSprint(C, D)
    Z.pop()
    Z.reverse()
    return Z


def LCSprint(C, D):
    for i in range(0, np.shape(C)[0]):
        for j in range(0, np.shape(C)[1]):
            if(D[i][j]):
                print(Back.RED+str(int(C[i][j])), end=" ")
            else:
                print(Back.BLACK+str(int(C[i][j])), end=" ")
        print(Back.BLACK+"\n", end="")


keepGoing = 1
while keepGoing == 1:
    decision = input("To input sequences manually, press 1\nTo read sequence from file, press 2\nTo clear screen press 3\nTo exit press anything else\n")
    if int(decision) == 1:
        x = input("Insert length of a sequence 1\n")
        X = []
        for i in range(0, int(x)):
            X.append(input("Insert character\n"))
        x = input("Insert length of a sequence 2\n")
        Y = []
        for i in range(0, int(x)):
            Y.append(input("Insert character\n"))
        clear()
        print(X)
        print(Y)
        Z = LCS(X ,Y, len(X), len(Y))
        print(Z)
    elif int(decision) == 2:
        x = input("Write path to the file 1\n")
        f = open(str(x), "r")
        X = []
        for i in f:
            X.append(i)
        f.close()
        x = input("Write path to the file 2\n")
        f = open(str(x), "r")
        Y = []
        for i in f:
            Y.append(i)
        f.close()
        print(X)
        print(Y)
        Z = LCS(X, Y, len(X), len(Y))
        print(Z)
    elif int(decision) == 3:
        clear()
    else:
        keepGoing = 0
            