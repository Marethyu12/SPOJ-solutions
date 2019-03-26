#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed;
	cout << setprecision(6);
	
	int n, m;
	int a, b, p;
	
	while (true)
	{
		cin >> n;
		
		if (n == 0)
			break;
		
		cin >> m;
		
		double dp[n][n];
		
		fill_n(*dp, n * n, 0.0);
		
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> p;
			
			dp[a - 1][b - 1] = dp[b - 1][a - 1] = (double) p / 100.0;
		}
		
		for (int i = 0; i < n; ++i)
			dp[i][i] = 1.0;
		
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);//that's how to calculate probability
		
		cout << (dp[0][n - 1] * 100.0) << " percent\n";
	}
	
	return 0;
}