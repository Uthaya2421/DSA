def display(arr):
    print(' '.join(map(str, arr)))


def insertion_sort(arr, l, h):
    for i in range(l+1, h+1):
        val = arr[i]
        j = i
        while j > l and arr[j-1] > val:
            arr[j] = arr[j-1]
            j -= 1
        arr[j] = val


def part(arr, l, h):
    pivot = arr[h]
    i = l
    j = l
    for i in range(l, h):
        if arr[i] < pivot:
            arr[j], arr[i] = arr[i], arr[j]
            j += 1
    arr[j], arr[h] = arr[h], arr[j]
    return j


def quick_sort(arr, l, h, T):
    if l < h:
        j = part(arr, l, h)

        quick_sort(arr, l, j-1, T)
        quick_sort(arr, j+1, h, T)
        return arr


def sort(arr, l, h, t):
    while l < h:
        if h-l+1 < t:
            insertion_sort(arr, l, h)
            break
        else:
            pivot = part(arr, l, h)
            if pivot-l < h - pivot:
                sort(arr, l, pivot-1, t)
                l = pivot + 1
                display(arr)
            else:
                sort(arr, pivot+1, h, t)
                h = pivot - 1
                display(arr)


lst = list(map(int, input().split()))

arr = []

for i in range(lst[0]):
    arr.append(lst[i+2])

sort(arr, 0, lst[0]-1, lst[1])
display(arr)
