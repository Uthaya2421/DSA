
def display(arr):
    if len(arr) != 0:
        for i in arr:
            print(str(i)+' ', end='')
    # print(' '.join(map(str, arr)))


def insertion_sort(arr):
    for i in range(1, len(arr)):
        val = arr[i]
        j = i - 1
        while j >= 0 and arr[j] < val:
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

    for i in range(m-1, -1, -1):
        display(arr[i])

    for i in range(m-1, -1, -1):
        arr[i] = insertion_sort(arr[i])
        display(arr[i])

    k = 0
    for i in range(m-1, -1, -1):
        for j in range(len(arr[i])):
            l[k] = arr[i][j]
            k += 1
    return l


arr = list(map(str, input().split()))
l = []
for i in range(2, len(arr)):
    l.append(float(arr[i]))
bucket_sort(l, int(arr[1]))
display(l)
