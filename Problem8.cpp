#include <iostream>
using namespace std;

// Maximum Sum Contiguous Subarray
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
		{
			cin >> arr[i];
		}
		long long currentSum = 0, currentMax = -100000000;
		for (int i = 0; i < n; i++)
		{
			currentSum += arr[i];
			if (currentSum > currentMax)
				currentMax = currentSum;
			if (currentSum < 0)
				currentSum = 0;
		}
		cout << currentMax << "\n";
	}
	return 0;
}