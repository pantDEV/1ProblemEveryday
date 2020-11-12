#include<bits/stdc++.h>
using namespace std;

#define LOCAL 1

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int i = 0;
	while (i < n)
	{
		if (i & 1) // put next positive number if present
		{
			int ind = i;
			while (ind < n && arr[ind] < 0)
				ind++;
			if (ind < n)
			{
				int temp = arr[ind];
				while (ind > i)
				{
					arr[ind] = arr[ind - 1];
					ind--;
				}
				arr[i] = temp;
			}

		}
		else   // put next negative number in this place
		{
			int ind = i;
			while (ind < n && arr[ind] >= 0)
				ind++;
			if (ind < n)
			{
				int temp = arr[ind];
				while (ind > i)
				{
					arr[ind] = arr[ind - 1];
					ind--;
				}
				arr[i] = temp;
			}
		}
		i++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}