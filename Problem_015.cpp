#include<bits/stdc++.h>
using namespace std;

// Next Permutation


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = n - 2;
        while (ind >= 0 && nums[ind] >= nums[ind + 1])
            ind--;
        int temp = ind;
        int high = n - 1;
        ind++;
        while (ind < high)
        {
            swap(nums[ind], nums[high]);
            ind++;
            high--;
        }
        if (temp >= 0)
        {
            int ind = temp + 1;
            while (ind < n && nums[ind] <= nums[temp])
                ind++;
            if (ind < n)
                swap(nums[temp], nums[ind]);
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int > v;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    Solution obj;
    obj.nextPermutation(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
