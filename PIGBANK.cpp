#include <bits/stdc++.h>

#define INF 0x7FFFFFFF

using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	long _start = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int E, F;
	int N;
	int P, W;
	
	cin >> T;
	
	while (T--)
	{
		cin >> E >> F;
		cin >> N;
		
		int price[N];
		int weight[N];
		
		for (int i = 0; i < N; ++i)
			cin >> price[i] >> weight[i];
		
		int max_weight = F - E;
		
		ll dp[max_weight + 1];
		
		dp[0] = 0;
		
		for (int i = 1; i <= max_weight; ++i)
		{
			dp[i] = INF;
			
			for (int j = 0; j < N; ++j)
				if (i - weight[j] >= 0 && dp[i - weight[j]] != INF)
					dp[i] = min(dp[i], price[j] + dp[i - weight[j]]);
		}
		
		if (dp[max_weight] != INF)
			cout << "The minimum amount of money in the piggy-bank is " << dp[max_weight] << ".\n";
		else
			cout << "This is impossible.\n";
	}
	
#ifndef ONLINE_JUDGE
    cout << "\nprocess terminated in " << (clock() - _start) << "ms\n";
#endif
	return 0;
}