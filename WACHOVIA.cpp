#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int w, n;
	
	cin >> T;
	
	while (T--)
	{
		cin >> w >> n;
		
		int weight[n];
		int value[n];
		
		for (int i = 0; i < n; ++i)
			cin >> weight[i] >> value[i];
		
		int dp[w + 1][n + 1];
		
		for (int i = 0; i <= w; ++i)
			for (int j = 0; j <= n; ++j)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else if (weight[j - 1] > i)
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = max(value[j - 1] + dp[i - weight[j - 1]][j - 1], dp[i][j - 1]);
			}
		
		cout << "Hey stupid robber, you can get " << dp[w][n] << ".\n";
	}
	
	return 0;
}