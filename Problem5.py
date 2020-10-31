# Move all negative numbers to beginning and 
# positive to end with constant extra space
# Two Pointer approach

def swap(arr,i,j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

t = int(input())
while t > 0:
    n = int(input())
    arr = [int(i) for i in input().split()]
    low = 0
    high = n-1
    while low < high:
        if arr[low] >= 0 and arr[high] < 0:
            swap(arr,low,high)
            low = low + 1
            high = high - 1
        elif arr[low] < 0:
            low = low + 1
        elif arr[high] > 0:
            high = high - 1

    print(*arr)
    t = t-1