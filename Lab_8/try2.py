
def quick_sort(arr, l, h):
    if(h == 0):
        return
    i = l+1
    j = h

    while(arr[i] < arr[l] and i < h):
        i += 1
    while(arr[j] > arr[l] and l < j):
        j -= 1

    if i > j and i == h and j == l:
        t = arr[l]
        arr[l] = arr[j]
        arr[j] = t
        quick_sort(arr, 0, j-1)
        quick_sort(arr, j+1, h)
    else:
        t = arr[i]
        arr[i] = arr[j]
        arr[j] = t
        quick_sort(arr, l, h)


# lst = list(map(int, input().split()))
arr = [7, 2, 11, 3, 13, 1]

# for i in range(lst[0]):
#     arr.append(lst[i+2])

quick_sort(arr, 0, 5)
print(arr)
