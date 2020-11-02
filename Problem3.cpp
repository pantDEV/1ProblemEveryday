#include <iostream>
using namespace std;

// finding kth smallest element using quicksort+random partition
// expected time complexity - O(n)
// Worst Case time compleixity - O(n^2)

int partition(int arr[], int low, int high)
{
	int i = low - 1, j = low;
	while (j < high)
	{
		if (arr[j] < arr[high])
		{
			i++;
			//swap arr[i] and arr[j]
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
		else
			j++;
	}
	i++;
	swap(arr[i], arr[high]);
	return i;
}

int randomPartition(int arr[], int low, int high)
{
	int n = high - low + 1;
	int pivot = rand() % n;
	swap(arr[low + pivot], arr[high]);
	return partition(arr, low, high);
}

int quick(int arr[], int low, int high, int k)
{
	if (low <= high)
	{
		int pivot = randomPartition(arr, low, high);
		if (pivot < k)
			quick(arr, pivot + 1, high, k);
		else if (pivot > k)
			quick(arr, low, pivot - 1, k);
		else
			return arr[pivot];
	}
}

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
		int n;
		cin >> n;
		int arr[n], k;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cin >> k;
		int ans = quick(arr, 0, n - 1, k - 1);
		cout << ans << '\n';
	}
	return 0;
}