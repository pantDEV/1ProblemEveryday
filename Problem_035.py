# Minimum merge opertations (add two elements) to make array a palindrome

t = int(input())

while t > 0:
    n = int(input())
    arr = [int(i) for i in input().split()]
    ans = 0
    ptr1 = 0
    ptr2 = n-1
    while ptr1 < ptr2:
        
        if arr[ptr1] == arr[ptr2]:
            ptr1 = ptr1 + 1
            ptr2 = ptr2 - 1

        elif arr[ptr1] > arr[ptr2]:
            ans = ans + 1
            arr[ptr1+1] = arr[ptr1+1] + arr[ptr1]
            ptr1 = ptr1 + 1

        else:
            ans = ans + 1
            arr[ptr2-1] = arr[ptr2-1] + arr[ptr2]
            ptr2 = ptr2 - 1

    print(ans)

    t = t-1
    