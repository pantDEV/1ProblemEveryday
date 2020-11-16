# Task is to check whether arr2[] is a subset of arr1[] or not.
import time


def function1(arr1, arr2):
    flag = 0
    if all(a in arr1 for a in arr2):
        flag = 1
    if flag:
        return "Yes"
    else:
        return "No"


def function2(arr1, arr2):
    if set(arr2).issubset(set(arr1)):
        return "Yes"
    else:
        return "No"


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        m, n = map(int, input().split())
        list1 = [int(i) for i in input().split()]
        list2 = [int(i) for i in input().split()]
        start_time = time.time()
        print(function1(list1, list2))
        print("using list all running time = {}".format(time.time()-start_time))
        start_time = time.time()
        print(function2(list1, list2))
        print("using set issubset running time = {}".format(time.time() - start_time))
        t = t - 1
