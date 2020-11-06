#include<bits/stdc++.h>
using namespace std;
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.
*/

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int i = 0, cou = 0;
    while (i < n && cou < n)
    {
        while (nums[i] != i + 1 && cou < n)
        {
            swap(nums[i], nums[nums[i]]);
            cou++;
        }
        i++;
    }
    for (int i = 0; i < n + 1; i++)
    {
        if (nums[i]  != i + 1)
            return nums[i];
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cout << findDuplicate(v);
    return 0;
}
