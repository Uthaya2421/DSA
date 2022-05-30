
def swap(arr, a, b):
    t = arr[a]
    arr[a] = arr[b]
    arr[b] = t


def create_heap(heap, i, n):
    l = 2*(i+1) - 1
    r = 2*(i + 1)
    if(l <= n and heap[i] > heap[l]):
        small = l
    else:
        small = i
    if(r <= n and heap[small] > heap[r]):
        small = r
    if(small != i):
        swap(heap, i, small)
        create_heap(heap, small, n)


def indx(arr, val):
    for i in range(len(arr)):
        if(arr[i] == val):
            return i
    return -1


def sort(heap, n):
    if(n > 1):
        swap(heap, 0, n-1)
        i = (n)//2 - 1
        for j in range(i, -1, -1):
            create_heap(heap, j, n-2)
        sort(heap, n-1)


def display(heap):
    print(' '.join(map(str, heap)))


n = 0
while(True):
    arr = list(map(int, input().split()))
    if(arr[0] == 1):
        heap = []
        for i in range(arr[1]):
            heap.append(arr[i+2])
        n = arr[1]
        i = (n)//2 - 1
        for j in range(i, -1, -1):
            create_heap(heap, j, n-1)
        display(heap)
    elif(arr[0] == 2):
        if(n == 0):
            print("Heap does not exist")
        else:
            heap.append(arr[1])
            n = len(heap)
            i = (n)//2 - 1
            for j in range(i, -1, -1):
                create_heap(heap, j, n-1)
            display(heap)
    elif(arr[0] == 3):
        if(n == 0):
            print("Heap does not exist")
        else:
            swap(heap, 0, len(heap)-1)
            heap.pop(len(heap)-1)
            n = len(heap)
            i = (n)//2 - 1
            for j in range(i, -1, -1):
                create_heap(heap, j, n-1)
            display(heap)
    elif(arr[0] == 4):
        if(n == 0):
            print("Heap does not exist")
        else:
            i = indx(heap, arr[1])
            if(i == -1):
                print("Integer not found")
            else:
                swap(heap, i, len(heap)-1)
                heap.pop(len(heap)-1)
                n = len(heap)
                i = (n)//2 - 1
                for j in range(i, -1, -1):
                    create_heap(heap, j, n-1)
                display(heap)
    elif(arr[0] == 5):
        n = len(heap)
        sort(heap, n)
        display(heap)

    elif(arr[0] == -1):
        exit()
