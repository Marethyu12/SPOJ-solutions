#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll max_coins(ll *monsters, int N)
{
	if (N == 1)
		return monsters[N - 1];
	
	if (N == 2)
		return max(monsters[N - 2], monsters[N - 1]);
	
	return max(max_coins(monsters, N - 2) + monsters[N - 1], max_coins(monsters, N - 1));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int N;
	
	cin >> T;
	
	for (int cn = 1; cn <= T; ++cn)
	{
		cin >> N;
		
		ll monsters[N];
		
		for (int i = 0; i < N; ++i)
			cin >> monsters[i];
		
		ll DP[N + 1];
		
		DP[1] = monsters[0];
		DP[2] = max(monsters[0], monsters[1]);
		
		for (int i = 3; i <= N; ++i)
			DP[i] = max(DP[i - 2] + monsters[i - 1], DP[i - 1]);
		
		cout << "Case " << cn << ": " << DP[N] << "\n";
	}
	
	return 0;
}
