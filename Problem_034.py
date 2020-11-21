# Minimum swaps and K together 

t = int(input())

while t > 0:
    n = int(input())
    arr = [int(i) for i in input().split()]
    k = int(input())
    
    count = 0
    
    for i in range(n):
        if arr[i] <= k:
            count = count + 1
        
    i = 0
    j = 0
    greater = 0
    ans = count
    while j < n and i <= n-count:

        if arr[j] > k:
            greater = greater + 1
        
        if j >= count-1:
            ans = min(ans, greater)
            if arr[i] > k:
                greater = greater - 1
            i = i + 1
        j = j + 1

    print(ans)

    t = t-1
    