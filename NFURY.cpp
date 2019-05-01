#include <bits/stdc++.h>

#define INF 0x7FFFFFFF

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int a;
	
	cin >> T;
	
	while (T--)
	{
		cin >> a;
		
		int dp[a + 1];
		
		dp[0] = 0;
		
		for (int i = 1; i <= a; ++i)
		{
			dp[i] = INF;
			
			for (int j = 1; j * j <= i; ++j)
				dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
		
		cout << dp[a] << "\n";
	}
	
	return 0;
}