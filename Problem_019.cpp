// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

/*
    Given three arrays sorted in increasing order.
    Find the elements that are common in all three arrays.
*/
// } Driver Code Ends


class Solution
{
public:
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        vector<int> v;
        int i = 0, j = 0, k = 0, ind = 0;
        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                if (!ind || v[ind - 1] != A[i])
                {
                    v.push_back(A[i]);
                    ind++;
                }
                i++; j++; k++;
            }
            else if (A[i] <= B[j] && A[i] <= C[k])
            {
                if (A[i] == B[j])j++;
                if (A[i] == C[k])k++;
                i++;
            }
            else if (B[j] <= A[i] && B[j] <= C[k])
            {
                if (A[i] == B[j])i++;
                if (B[j] == C[k])k++;
                j++;
            }
            else if (C[k] <= A[i] && C[k] <= B[j])
            {
                if (C[k] == B[j])j++;
                if (C[k] == A[i])i++;
                k++;
            }
        }
        return v;
    }

};

// { Driver Code Starts.

int main ()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];

        Solution ob;

        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0)
            cout << -1;
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}  // } Driver Code Ends