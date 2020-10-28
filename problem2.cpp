#include<iostream>
using namespace std;

//Find maximum and minimum of an array using minimum no of comparisions
//Tournament method
//Recursive
int mini = 1000000000;
int maxi = -1;
pair<int, int> getMinMax(int arr[], int low, int high)
{
	pair<int, int> leftMinMax, rightMinMax, varMinMax;
	varMinMax.first = 0;
	if (low == high)
	{
		varMinMax.first  = arr[low];
		varMinMax.second = arr[high];
	}
	else if (low == high - 1)
	{
		if (arr[low] < arr[high]) {
			varMinMax.first = arr[low];
			varMinMax.second = arr[high];
		}
		else
		{
			varMinMax.first = arr[high];
			varMinMax.second = arr[low];
		}
	}
	else
	{
		int mid = (low + high) / 2;
		leftMinMax  = getMinMax(arr, low, mid);
		rightMinMax = getMinMax(arr, mid + 1, high);
		//compare the min and max of left array and right array
		if (leftMinMax.first < rightMinMax.first)
			varMinMax.first = leftMinMax.first;
		else
			varMinMax.first = rightMinMax.first;

		if (leftMinMax.second > rightMinMax.second)
			varMinMax.second = leftMinMax.second;
		else
			varMinMax.second = rightMinMax.second;
	}
	//cout << varMinMax.first << " " << varMinMax.second << "\n";
	return varMinMax;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, mini, maxi;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	pair<int, int> ans;
	ans = getMinMax(arr, 0, n - 1);
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}