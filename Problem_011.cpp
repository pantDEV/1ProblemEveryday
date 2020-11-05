#include <iostream>
using namespace std;
/*
Given an array of integers where each element represents
the max number of steps that can be made forward from that
element. The task is to find the minimum number of jumps to
reach the end of the array (starting from the first element).
If an element is 0, then cannot move through that element.

O(n) solution
*/
int main() {
	//code
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int i = 1, ans = 0, ind = 0;
		while (i < n)
		{
			ans++;
			int max1 = -1;
			int cou = 0, temp = ind;
			while (i <= arr[temp] + temp && i < n)
			{
				if (max1 < arr[i] + cou)
				{
					max1 = arr[i] + cou;
					ind = i;
				}
				cou++;
				i++;
			}
			if (max1 <= 0)
				break;
		}
		if (i < n)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
	return 0;
}