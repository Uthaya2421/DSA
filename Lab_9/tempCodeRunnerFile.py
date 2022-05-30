from Lab_8.try4 import insertion_sort


def display(arr):
    print(' '.join(map(str, arr)))


def insertion_sort(arr):
    for i in range(1, len(arr)):
        val = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > val:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = val
    return arr


def bucket_sort(l, m):
    arr = []

    for i in range(m):
        arr.append([])

    for j in l:
        ind = int(m*j)
        arr[ind].append(j)

    for i in range(m):
        arr[i] = insertion_sort(arr[i])

    k = 0
    for i in range(m):
        for j in range(len(arr[i])):
            l[k] = arr[i][j]
            k += 1
    return l


arr = list(map(int, input().split()))
l = []
for i in range(2, len(arr)):
    l.append(arr[i])
bucket_sort(l)
display(l)
