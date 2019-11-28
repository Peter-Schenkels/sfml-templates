





def between(array):
    result = []
    for i in range(0, len(array)):
        j = len(array) - 1
        sum = 0
        for k in range(i, j):
            sum = sum + array[k]
        result.append(sum)
    return result



ar = [22, 333, 4, 55, 52, 334, 32]
print(between(ar))