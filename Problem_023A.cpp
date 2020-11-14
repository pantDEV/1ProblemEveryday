// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

// Maximum Product Subarray

//User function template for C++
class Solution {
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
		// code here
		long long ans = -1000, product = 1;
		for (int i = 0; i < n; i++)
		{
			product *= arr[i];
			ans = max(ans, product);
			if (arr[i] == 0)
				product = 1;
		}
		product = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			product *= arr[i];
			ans = max(ans, product);
			if (arr[i] == 0)
				product = 1;
		}
		return ans;
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, i;
		cin >> n;
		int arr[n];
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.maxProduct(arr, n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends