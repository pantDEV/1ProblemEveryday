# Smallest subarray with sum greater than x

t = int(input())

while t > 0:
    n, x = map(int, input().split())
    arr = [int(i) for i in input().split()]

    prefix = [0] * n
    prefix[0] = arr[0]

    for i in range(1, n):
        prefix[i] = arr[i] + prefix[i - 1]

    index = 0
    ans = n + 1

    for i in range(n):

        if arr[i] > x:
            ans = 1
            break

        if prefix[i] > x:
            while index < i:
                ans = min(ans, i - index + 1)
                if prefix[i] - prefix[index] > x:
                    index = index + 1
                else:
                    break
        i = i + 1

    print(ans)
    t = t - 1