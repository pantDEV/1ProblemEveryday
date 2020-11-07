// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;
//User function template for C++

class Solution {
public:
	void merge(ll arr1[], ll arr2[], int n, int m) {
		// code here
		int i1 = 0, i2 = 0, index = 0;
		ll mod = 1000005;
		while (i1 < n && i2 < m)
		{
			ll a = arr1[i1] % mod;
			ll b = arr2[i2] % mod;
			if (b < a)
			{
				if (index < n)
					arr1[index] += (b * mod);
				else
					arr2[index - n] += (b * mod);
				i2++;
			}
			else
			{
				if (index < n)
					arr1[index] += (a * mod);
				else
					arr2[index - n] += (a * mod);
				i1++;
			}
			index++;
		}
		while (i1 < n)
		{
			ll a = arr1[i1] % mod;
			if (index < n)
				arr1[index] += (a * mod);
			else
				arr2[index - n] += (a * mod);
			index++;
			i1++;
		}
		while (i2 < m)
		{
			ll b = arr2[i2] % mod;
			if (index < n)
				arr1[index] += (b * mod);
			else
				arr2[index - n] += (b * mod);
			i2++;
			index++;
		}
		for (int i = 0; i < n; i++)
			arr1[i] /= mod;
		for (int i = 0; i < m; i++)
			arr2[i] /= mod;
	}
};

// { Driver Code Starts.
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, m, i;
		cin >> n >> m;
		ll arr1[n], arr2[m];
		for (i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		Solution ob;
		ob.merge(arr1, arr2, n, m);
		for (i = 0; i < n; i++) {
			cout << arr1[i] << " ";
		}
		for (i = 0; i < m; i++) {
			cout << arr2[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends