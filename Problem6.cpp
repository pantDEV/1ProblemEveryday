#include <iostream>
using namespace std;
// Union of two arrays-
int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, ans = 0;
		cin >> n >> m;
		int arr[100005] = {0};
		for (int i = 0; i < n + m; i++)
		{
			int a;
			cin >> a;
			arr[a]++;
		}
		for (int i = 0; i < 100005; i++)
			if (arr[i])
				ans++;
		cout << ans << "\n";

	}
	return 0;
}