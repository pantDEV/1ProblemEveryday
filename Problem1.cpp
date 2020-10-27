#include<iostream>
using namespace std;

//Reverse an array interatively-
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
	for (int i = 0; i < n / 2; i++)
	{
		int temp = arr[n - i - 1];
		arr[n - i - 1] = arr[i];
		arr[i] = temp;
	}
//print array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}