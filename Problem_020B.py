
# rearrange-array-alternating-positive-negative-items in O(n) time
# order does not matter

n = int(input())
arr = [int(i) for i in input().split()]

index1 = 0
index2 = 1

while index2 < n and index1 < n:
    if 0 <= arr[index1] and 0 > arr[index2]:
        temp = arr[index1]
        arr[index1] = arr[index2]
        arr[index2] = temp
    if arr[index1] < 0:
        index1 = index1 + 2
    if arr[index2] >= 0:
        index2 = index2 + 2
print(arr)

