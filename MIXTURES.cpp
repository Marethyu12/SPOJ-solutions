#include <bits/stdc++.h>

#define INF 0x7FFFFFFF

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	while (cin >> n)
	{
		int color[n];
		
		for (int i = 0; i < n; ++i)
			cin >> color[i];
		
		int dp[n][n];
		int mixture[n][n];
		
		for (int i = 0; i < n; ++i)
		{
			dp[i][i] = 0;
			mixture[i][i] = color[i];
		}
		
		for (int l = 2; l <= n; ++l)
			for (int i = 0; i < n - l + 1; ++i)
			{
				int j = i + l - 1;
				
				dp[i][j] = INF;
				mixture[i][j] = (mixture[i][j - 1] + color[j]) % 100;
				
				for (int k = i; k < j; ++k)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mixture[i][k] * mixture[k + 1][j]);
			}
		
		cout << dp[0][n - 1] << "\n";
	}
	
	return 0;
}