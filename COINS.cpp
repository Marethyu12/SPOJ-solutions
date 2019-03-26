#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> dp;

ll max_dollars(ll n)
{
	if (dp.find(n) == dp.end())
	{
		if (n < 12L)
			dp[n] = n;
		else
			dp[n] = max_dollars(n / 2L) + max_dollars(n / 3L) + max_dollars(n / 4L);
	}
	
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;
	
	while (cin >> n)
		cout << max_dollars(n) << "\n";
	
	return 0;
}