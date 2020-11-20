#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
#define int ll
#define pb push_back
#define fi first
#define se second
#define pi 3.14159265359
#define fo(i,n) for(int i = 0; i < n; i++)


/*
	Find the maximum element in an array which is
	first increasing and then decreasing.

*/
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	io
	int n;
	cin >> n;
	int arr[n];

	fo(i, n)
	cin >> arr[i];

	int low = 0, high = n - 1, ans;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (mid == 0 || mid == n - 1) {
			ans = mid;
			break;
		}

		if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
		{
			ans = mid;
			break;
		}

		else if (arr[mid] < arr[mid - 1])
		{
			high = mid - 1;
		}

		else if (arr[mid] < arr[mid + 1])
		{
			low = mid + 1;
		}
	}
	cout << arr[ans] << endl;
	return 0;
}
