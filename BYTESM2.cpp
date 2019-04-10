#include <bits/stdc++.h>

#define MAXN 100

using namespace std;

inline int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int h, w;
	
	cin >> T;
	
	while (T--)
	{
		cin >> h >> w;
		
		int stones[h][w];
		
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> stones[i][j];
		
		int dp[h][w];
		
		for (int i = h - 1; i >= 0; --i)
			for (int j = 0; j < w; ++j)
			{
				int bot_left = (i == h - 1 || j == 0) ? 0 : dp[i + 1][j - 1];
				int bot = (i == h - 1) ? 0 : dp[i + 1][j];
				int bot_right = (i == h - 1 || j == w - 1) ? 0 : dp[i + 1][j + 1];
				
				dp[i][j] = stones[i][j] + max(bot_left, bot, bot_right);
			}
		
		int max_stones = dp[0][0];
		
		for (int j = 1; j < w; ++j)
			max_stones = max(max_stones, dp[0][j]);
		
		cout << max_stones << "\n";
	}
	
	return 0;
}