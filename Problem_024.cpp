// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Longest Consecutive Subsequence

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
    int  t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
    //Your code here
    int hash[100005] = {0};
    int maxi = -1;
    for (int i = 0; i < N; i++)
    {
        hash[arr[i]]++;
        maxi = max(arr[i], maxi);
    }
    int ans = 0, MaxSoFar = 0;
    for (int i = 1; i <= maxi; i++)
    {
        if (hash[i] && hash[i - 1])
            MaxSoFar++;
        else
        {
            ans = max(ans, MaxSoFar);
            MaxSoFar = 0;
        }
    }
    ans = max(ans, MaxSoFar);
    return ans + 1;
}