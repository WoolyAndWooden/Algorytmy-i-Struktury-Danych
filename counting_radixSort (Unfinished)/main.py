def countSort(A, B, k):
    C = [0] * (k)

    for j in range(0, len(A)):
        C[int(A[j])] = C[int(A[j])] + 1

    print(C)


A = ["synowa", "mama", "brat", "córka", "dziadek", "babcia", "syn",
     "bratowa", "ciocia", "dziecko", "teściowa", "stryjek",
     "szwagier", "tata", "wujek", "teść", "siostra", "zięć"]
B = [0]
countSort(A, B, 256)