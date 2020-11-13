#include <bits/stdc++.h>
using namespace std;

// find if subarray sum is 0

int main() {
	//code
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, ans = 0;
		cin >> n;
		int arr[n];
		unordered_map<long long, int> map1;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i)
			{
				arr[i] += arr[i - 1];
			}
			map1[arr[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (!arr[i] || map1[arr[i]] >= 2 )
			{
				ans = 1;
				break;
			}
		}
		if (ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}