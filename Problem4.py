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
            swap(arr,i,ptr1)
            ptr1 += 1
            
        if arr[i] == 2:
            swap(arr,ptr2,i)
            if arr[i] != 2:
                i = i-1:
            ptr2 -= 1
            
    print (*arr)
    
    t = t - 1
        
            