#include <bits/stdc++.h>

#define MAXN 1002
#define INF 0x7FFFFFFF

using namespace std;

int dp[MAXN][MAXN];
int cut[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int length;
	int n;
	
	while (cin >> length >> n)
	{
		n += 2;
		
		int pos[n];
		
		for (int i = 1; i < n - 1; ++i)
			cin >> pos[i];
		
		pos[0] = 0;
		pos[n - 1] = length;
		
		for (int i = 0; i < n - 1; ++i)
			dp[i][i + 1] = 0;
		
		for (int i = 0; i < n - 2; ++i)
		{
			dp[i][i + 2] = pos[i + 2] - pos[i];
			cut[i][i + 2] = i + 1;
		}
		
		for (int l = 4; l <= n; ++l)
			for (int i = 0; i < n - l + 1; ++i)
			{
				int j = i + l - 1;
				
				dp[i][j] = INF;
				
				for (int k = cut[i][j - 1]; k <= cut[i + 1][j]; ++k)
				{
					int q = dp[i][k] + dp[k][j] + pos[j] - pos[i];
					
					if (dp[i][j] > q)
					{
						dp[i][j] = q;
						cut[i][j] = k;
					}
				}
			}
		
		cout << dp[0][n - 1] << "\n";
	}
	
	return 0;
}