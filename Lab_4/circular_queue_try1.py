lst = []
a = int(input())
lst = [0 for i in range(a)]
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


def enQueue(element):
    global front
    global rear
    if (isfull()):
        print("\n Queue is full!! \n")
    else:
        if (front == -1):
            front = 0
        rear = (rear + 1) % a
        lst[rear] = element
        print("Inserted ->", element)


def deQueue(lst):
    global front, rear

    if (isempty()):
        print("\n Queue is empty !! \n")
        # return (-1)
    else:
        element = lst[front]
        lst[front] = 0
        if (front == rear):
            front = -1
            rear = -1

        else:
            front = (front + 1) % a

        print("\n Deleted element -> ", element)
        # return (element)


def disp():
    global front, rear
    print(lst[front], front)
    print(lst[rear], rear)
    print(lst)


i = int(input())
while(i != -1):
    if(i == 1):
        b = int(input())
        enQueue(b)
        print(lst)

    elif(i == 2):
        deQueue(lst)
    elif(i == 3):
        disp()
    elif(i == -1):
        print(lst)
        exit()

    i = int(input())
