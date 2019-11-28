
def partition(a, hi, lo):
    pivot = a[hi]
    i = lo
    for j in range(lo, hi-1):
        if a[j] < pivot:
            a[i],a[j] = a[j],a[i]
            i+=1
    a[i],a[hi] = a[hi],a[i]
    return i

def quickSort(a, hi, lo):
    if lo > hi:
        return a
    p = partition(a, lo, hi)
    a = quickSort(a, lo, p - 1)
    a = quickSort(a, p + 1, hi)
    return a




a = [10, 7, 8, 9, 1, 5]
hi = len(a)
print(quickSort(a,0,hi))

