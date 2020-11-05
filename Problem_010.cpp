#include <iostream>
using namespace std;
* /
/*
Given an array arr of N integers.
Find the contiguous sub-array with maximum sum.

Kadane's algo
*/
int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		long long currentSum = 0, maxSum = -100000000;
		for (int i = 0; i < n; i++)
		{
			currentSum += arr[i];
			if (currentSum > maxSum)
				maxSum = currentSum;
			if (currentSum < 0)
				currentSum = 0;
		}
		cout << maxSum << "\n";
	}
	return 0;
}
