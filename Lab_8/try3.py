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
    display(arr)


def part(arr, l, h):
    swap = 0
    i = l-1
    j = l
    while j <= h-1:

        if arr[j] <= arr[h]:
            i += 1
            t = arr[i]
            arr[i] = arr[j]
            arr[j] = t
        if(i != j):
            swap += 1
        j += 1
    if(swap > 0):
        t = arr[i+1]
        arr[i+1] = arr[h]
        arr[h] = t
    return i+1


def quick_sort(arr, l, h, T):
    if l < h:
        j = part(arr, l, h)
        display(arr)
        if j-1-l > T:
            quick_sort(arr, l, j-1, T)
        elif(j-1-l > 0):
            insertion_sort(arr, l, j-1)
            
        if h-j-1 > T:
            quick_sort(arr, j+1, h, T)
        elif(h-j-1 > 0):
            insertion_sort(arr, j+1, h)
            


lst = list(map(int, input().split()))

arr = []

for i in range(lst[0]):
    arr.append(lst[i+2])

quick_sort(arr, 0, lst[0]-1, lst[1])
