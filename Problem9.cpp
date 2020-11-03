/*
 Given an array arr[] denoting heights of N towers
 and a positive integer K, modify the heights of each
 tower either by increasing or decreasing them by K only once.
 Find out the minimum difference of the heights of shortest and
 longest modified towers.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
  int getMinDiff(int arr[], int n, int k) {
    // code here
    int max1 = -1, min1 = 1000000;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > max1)
        max1 = arr[i];
      if (arr[i] < min1)
        min1 = arr[i];
    }
    int ans = max1 - min1;
    sort(arr, arr + n);
    int i = 1;
    max1 -= k;
    min1 += k;
    if (max1 < min1)
      swap(max1, min1);
    while (i < n - 1)
    {
      int small = arr[i] - k;
      int big = arr[i] + k;
      if (small >= min1 || big <= max1)
      {
        i++;
        continue;
      }
      else
      {
        if (max1 - small <= big - min1)
          min1 = small;
        else
          max1 = big;
      }
      i++;
    }
    return min(ans, max1 - min1);
  }
};

// { Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.getMinDiff(arr, n, k);
    cout << ans << "\n";
  }
  return 0;
}  // } Driver Code Ends