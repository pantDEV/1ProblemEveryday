# Tapping Rain Water

t = int(input())

while t > 0:

    n = int(input())
    arr = [int(i) for i in input().split()]

    Right_to_Left_Highest = [0] * n
    Left_to_Right_Highest = [0] * n
    Right_to_Left_Highest[n-1] = n-1
    Left_to_Right_Highest[0] = 0

    for i in range(n-2, -1, -1):
        if arr[i] > arr[Right_to_Left_Highest[i+1]]:
            Right_to_Left_Highest[i] = i
        else:
            Right_to_Left_Highest[i] = Right_to_Left_Highest[i+1]

    for i in range(1, n, 1):
        if arr[i] > arr[Left_to_Right_Highest[i-1]]:
            Left_to_Right_Highest[i] = i
        else:
            Left_to_Right_Highest[i] = Left_to_Right_Highest[i-1]

    totalWater = 0

    index = Left_to_Right_Highest[n-1]
    i = index

    while i < n-1:
        in1 = i + 1
        index = Right_to_Left_Highest[in1]
        while in1 < index:
            totalWater = totalWater + arr[index] - arr[in1]
            in1 = in1 + 1
        i = index

    index = Left_to_Right_Highest[n-1]
    i = index

    while i > 0:
        in1 = i-1
        index = Left_to_Right_Highest[in1]
        while in1 > index:
            totalWater = totalWater + arr[index] - arr[in1]
            in1 = in1 - 1
        i = index

    print(totalWater)
    t = t - 1

