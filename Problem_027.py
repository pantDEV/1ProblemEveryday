# Triplet Sum in Array 

t = int(input())

while t > 0:
    flag = 0
    n, k = map(int, input().split())
    arr = [int(i) for i in input().split()]
    arr.sort()
    for i in range(1, n-1):
        low = 0
        high = n - 1
        while low < high:
            if arr[low] + arr[i] + arr[high] > k:
                high = high - 1
            elif arr[low] + arr[i] + arr[high] == k:
                flag = 1
                break
            else:
                low = low + 1
            if low == i:
                low = low + 1
            if high == i:
                high = high - 1
        if flag:
            break
    print(flag)
    t = t-1
