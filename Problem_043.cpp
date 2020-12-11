// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

vector<string> ans;
void recurse(int m[MAX][MAX], int n, int v1, int v2, bool visited[MAX][MAX], string s)
{
    if (v1 < 0 || v1 >= n - 1 || v2 < 0 || v2 >= n - 1)
        return;

    if (m[v1][v2] == 0)
        return;

    if (v1 == n - 1 && v2 == n - 1)
    {ans.push_back(s); return;}

    if (visited[v1][v2])
        return;

    visited[v1][v2] = 1;


    int l1 = v1, l2 = v2 - 1;
    recurse(m, n, l1, l2, visited, s + "L");

    l1 = v1 - 1, l2 = v2;
    recurse(m, n, l1, l2, visited, s + "U");

    l1 = v1 + 1, l2 = v2;
    recurse(m, n, l1, l2, visited, s + "D");

    l1 = v1, l2 = v2 + 1;
    recurse(m, n, l1, l2, visited, s + "R");

}


vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    // vector<string> ans;
    bool visited[n][n] = {0};
    recurse(m, n, 0, 0, visited, "");

    sort(ans.begin(), ans.end());
    return ans;
}
