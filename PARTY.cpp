#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int weight, n;
	
	while (true)
	{
		cin >> weight >> n;
		
		if (weight == 0 && n == 0)
			break;
		
		int weights[n];
		int values[n];
		
		for (int i = 0; i < n; ++i)
			cin >> weights[i] >> values[i];
		
		int DP[weight + 1][n + 1];
		
		for (int i = 0; i <= weight; ++i)
			for (int j = 0; j <= n; ++j)
			{
				if (i == 0 || j == 0)
					DP[i][j] = 0;
				else if (weights[j - 1] > i)
					DP[i][j] = DP[i][j - 1];
				else
					DP[i][j] = max(values[j - 1] + DP[i - weights[j - 1]][j - 1], DP[i][j - 1]);
			}
		
		int cost = weight;
		int fun = 0;
		
		for (int i = cost; i >= 0; --i)//We want a minimum cost for maximum fun
			if (fun <= DP[i][n])
			{
				fun = DP[i][n];
				cost = i;
			}
		
		cout << cost << " " << DP[weight][n] << "\n";
	}
	
	return 0;
}