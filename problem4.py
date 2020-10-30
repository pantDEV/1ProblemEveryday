#code
def swap(arr,i,j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
    
t = int(input())
while t>0:
    n = int(input())
    arr = [int(i) for i in input().split()]
    ptr1 = 0;
    ptr2 = n-1
    for i in range(n):
        if arr[i] == 0:
            while ptr1 < i and arr[ptr1] == 0:
                ptr1 = ptr1 + 1
            if ptr1 < i:
                swap(arr,i,ptr1)
                ptr1 += 1
            
        if arr[i] == 2:
            while ptr2 > i and arr[ptr2] == 2:
                ptr2 = ptr2 - 1
            if ptr2 >= i:
                swap(arr,ptr2,i)
                ptr2 -= 1
            
        if arr[i] == 0:
            while ptr1 < i and arr[ptr1] == 0:
                ptr1 = ptr1 + 1
            if ptr1 < i:
                swap(arr,i,ptr1)
                ptr1 += 1
            
    print (*arr)
    
    t = t - 1
        
            