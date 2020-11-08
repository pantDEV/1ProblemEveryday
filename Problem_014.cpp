#include<bits/stdc++.h>
using namespace std;

// Merge Intervals

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ans;
        if (intervals.size() == 0)return ans;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= intervals[i - 1][1])
            {
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
            }
            else
                ans.push_back(intervals[i - 1]);
        }
        ans.push_back(intervals[intervals.size() - 1]);
        return ans;
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
    vector<vector<int> > v;
    while (n--)
    {
        vector<int> a(2);
        cin >> a[0] >> a[1];
        v.push_back(a);
    }
    Solution obj;
    v = obj.merge(v);
    for (auto i : v)
    {
        cout << i[0] << " " << i[1] << "\n";
    }
    return 0;
}
