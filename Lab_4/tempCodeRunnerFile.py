
temp = 0
front = -1
rear = -1


def isfull():
    global front, rear

    if(rear == a-1 and front == 0):
        return True
    elif(front == rear + 1):
        return True
    else:
        return False


def isempty():
    global front
    if(front == -1):
        return True


def enQueue(lst1, lst):
    global front
    global rear
    tmp_front = front
    tmp_rear = rear
    k = 0
    v = lst.copy()

    for i in range(2, len(lst1)):
        if (isfull()):
            print("overflow")
            k = 1
            break
        else:

            if (front == -1):
                front = 0
            rear = (rear + 1) % a
            v[rear] = lst1[i]

    if(k == 0):
        print(' '.join(map(str, v)))
        return v
    else:
        front = tmp_front
        rear = tmp_rear
        return lst


def deQueue(count, lst):
    global front, rear
    tmp_front = front
    tmp_rear = rear
    k = 0
    u = lst.copy()

    for i in range(count):
        if (isempty()):
            print("underflow")
            k = 1
            break

        else:
            element = lst[front]
            u[front] = 0
            if (front == rear):
                front = -1
                rear = -1

            else:
                front = (front + 1) % a
    if(k == 0):
        print(' '.join(map(str, u)))
        return u
    else:
        front = tmp_front
        rear = tmp_rear
        return lst


def leng(lst):
    count = 0
    for i in lst:
        if(i != 0):
            count += 1
    return count


def disp():
    global front, rear
    print(lst[front], front)
    print(lst[rear], rear)
    print(leng(lst))
    print(' '.join(map(str, lst)))


lst = []
a = int(input())
lst = [0 for i in range(a)]


while(True):
    lst1 = list(map(int, input().split()))
    if(lst1[0] == 1):
        lst = enQueue(lst1, lst)

    elif(lst1[0] == 2):
        lst = deQueue(lst1[1], lst)

    elif(lst1[0] == 3):
        disp()
    elif(lst1[0] == -1):
        exit()
