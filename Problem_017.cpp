#include<bits/stdc++.h>
using namespace std;

// Best time to buy and sell stock



class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int currentStock = prices[0];
		int currentProfit = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (currentStock <= prices[i])
			{
				currentProfit = max(currentProfit, prices[i] - currentStock);
			}
			else
			{
				currentStock = prices[i];
			}
		}
		return currentProfit;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int > v;
	while (n--)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	Solution obj;
	int ans = obj.maxProfit(v);
	cout << ans << endl;
	return 0;
}

