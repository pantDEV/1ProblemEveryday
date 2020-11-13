#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// find out factorial up to 1000

#define LOCAL 1

void multiply(int arr[], int *ind, int multiplier)
{
	int carry = 0;
	for (int i = 0; i < *ind; i++)
	{
		int product = multiplier * arr[i];
		arr[i] = product;
		arr[i] += carry;
		carry   = arr[i] / 10;
		arr[i]  = arr[i] % 10;
	}
	int i = *ind;
	while (carry)
	{
		arr[i++] += (carry % 10);
		carry /= 10;
	}

	(*ind) = i;

}

int main()
{
	io
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int arr[1000001] = {0};
		int n, ind = 1;
		cin >> n;
		arr[0] = 1;
		for (int i = 2; i <= n; i++)
		{
			multiply(arr, &ind, i);
		}
		int flag = 0;
		while (ind)
		{
			if (arr[ind - 1])flag = 1;
			if (flag)
			{
				cout << arr[ind - 1];
			}
			ind--;
		}
		cout << "\n";
	}
	return 0;
}