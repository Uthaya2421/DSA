def disp(arr):
    print(' '.join(map(str,arr)))

def insertion_sort(arr, low, n):
    for i in range(low + 1, n + 1):
        val = arr[i]
        j = i
        while j>low and arr[j-1]>val:
            arr[j]= arr[j-1]
            j-= 1
        arr[j]= val


def partition(arr, low, high):
    pivot = arr[high]
    i = j = low
    for i in range(low, high):
        if arr[i]<pivot:
            a[i], a[j]= a[j], a[i]
            j+= 1
    a[j], a[high]= a[high], a[j]
    return j


def quick_sort(arr, low, high):
    if low<high:
        pivot = partition(arr, low, high)
        quick_sort(arr, low, pivot-1)
        quick_sort(arr, pivot + 1, high)
        return arr


def hybrid_quick_sort(arr, low, high,t):
    while low<high:

        
        if high-low + 1<t:
            insertion_sort(arr, low, high)
            break

        else:
            pivot = partition(arr, low, high)

            
            if pivot-low<high-pivot:
                hybrid_quick_sort(arr, low, pivot-1,t)
                low = pivot + 1
                disp(arr)
            else:
                
                hybrid_quick_sort(arr, pivot + 1, high,t)
                high = pivot-1
                disp(arr)
                

# Driver code

a = list(map(int,input().split()))

arr =[]

for i in range(a[0]):
    arr.append(a[i+2])

hybrid_quick_sort(arr,0, a[0]-1, a[1])
disp(arr)
