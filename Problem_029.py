# Chololate Distribution Problem

t = int(input())

while t > 0:
    n = int(input())
    arr = [int(item) for item in input().split()]
    m = int(input())
    arr.sort()
    ans = arr[m-1] - arr[0]
    for i in range(1,n-m+1):
        ans = min(ans, arr[i+m-1]-arr[i])
    print(ans)
    t = t - 1