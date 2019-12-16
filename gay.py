from array import *


types = [1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000]

A = [[0 for x in range(1000)] for y in range(1000)]

def money(n, index):
    if A[n][index] != 0:
        return A[n][index]

    n = n - types[index]
    if n < 0:
        value = 0
    elif n == 0:
        value = 1 
    else:
        value = money(n, index) + money(n + types[index], index-1)
    A[n][index] = value
    return value


print(money(7, len(types) -1))