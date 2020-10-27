#include<iostream>
using namespace std;

//Reverse an array recursively-
void reverse(int arr[], int low, int high)
{
	if (low >= high)
		return;
	else {
		swap(arr[low], arr[high]);
		reverse(arr, low + 1, high - 1);
	}

}
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
//reverse array
	reverse(arr, 0, n - 1);
//print array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}