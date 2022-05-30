def display(arr):
    print(' '.join(map(str, arr)))


def insertion_sort(arr, l, h):
    for i in range(l, h+1):
        if i-1 >= l:
            temp = i
            for j in range(i-1, -1, -1):
                if arr[temp] < arr[j]:
                    t = arr[temp]
                    arr[temp] = arr[j]
                    arr[j] = t
                    temp = j
                else:
                    break


def part(arr, l, h):
    i = l+1
    j = h
    while True:

        while(arr[i] < arr[l] and i < h):
            i += 1
        while(arr[j] > arr[l] and l < j):
            j -= 1

        if i < j and i < h and j > l:
            t = arr[i]
            arr[i] = arr[j]
            arr[j] = t
        if i > j or i == h:
            break

    t = arr[l]
    arr[l] = arr[j]
    arr[j] = t
    display(arr)
    return j


def quick_sort(arr, l, h, T):
    if l < h:
        j = part(arr, l, h)
        if j-1-l > T:
            quick_sort(arr, l, j-1, T)
        else:
            insertion_sort(arr, l, j-1)
        if h-j-1 > T:
            quick_sort(arr, j+1, h, T)
        else:
            insertion_sort(arr, j+1, h)


lst = list(map(int, input().split()))
# lst = [6, 2, 7, 2, 11, 3, 13, 1]
arr = []

for i in range(lst[0]):
    arr.append(lst[i+2])

quick_sort(arr, 0, lst[0]-1, lst[1])
display(arr)
