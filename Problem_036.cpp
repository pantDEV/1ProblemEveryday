// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution
{
public:
	vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
	{
		// code here
		int k = 0;
		int n = r;
		int sum = 0, total = r * c;
		vector<int> result;
		while (sum < total)
		{

			for (int i = k; i < c; i++)
			{
				result.push_back(matrix[k][i]);
				sum++;
			}
			for (int i = k + 1; i < r; i++) {
				result.push_back(matrix[i][c - 1]);
				sum++;
			}
			for (int i = c - 2; i >= k; i--) {
				result.push_back(matrix[r - 1][i]);
				sum++;
			}
			for (int i = r - 2; i > k; i--) {
				result.push_back(matrix[i][k]);
				sum++;
			}
			k++;
			r--;
			c--;

		}
		while (result.size() != total)
			result.pop_back();
		return result;
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{
		int r, c;
		cin >> r >> c;
		vector<vector<int> > matrix(r);

		for (int i = 0; i < r; i++)
		{
			matrix[i].assign(c, 0);
			for ( int j = 0; j < c; j++)
			{
				cin >> matrix[i][j];
			}
		}

		Solution ob;
		vector<int> result = ob.spirallyTraverse(matrix, r, c);
		for (int i = 0; i < result.size(); ++i)
			cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends