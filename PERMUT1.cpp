#include <bits/stdc++.h>

using namespace std;

int DP[13][99];

int count_ways(int n, int k)
{
	if (DP[n][k] == -1)
	{
		if (n == 0)
			DP[n][k] = 0;
		else if (k == 0)
			DP[n][k] = 1;
		else
		{
			DP[n][k] = 0;
			
			for (int i = 0; i < n && k - i >= 0; ++i)
				DP[n][k] += count_ways(n - 1, k - i);
		}
	}
	
	return DP[n][k];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	fill_n(*DP, 13 * 99, -1);
	
	int T;
	int n, k;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> k;
		cout << count_ways(n, k) << "\n";
	}
	
	return 0;
}