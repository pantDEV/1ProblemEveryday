'''
code
cyclic rotation of the array by 1
array  1 2 3 4 5
result 5 1 2 3 4
'''
t = int(input())
while t > 0:
    n = int(input())
    arr = [int(i) for i in input().split()]
    temp = arr[n-1]
    for i in range(n-1,0,-1):
        arr[i] = arr[i-1]
    arr[0] = temp
    print(*arr)    
    t = t-1