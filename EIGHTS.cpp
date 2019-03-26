#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	ll n;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		ll ans = 192 + (n - 1) * 250;
		
		cout << ans << "\n";
	}
	
	return 0;
}