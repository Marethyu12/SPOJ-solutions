#include <bits/stdc++.h>

#define INF 0x7FFFFFFF

using namespace std;

struct Pack
{
	int weight;
	int price;
	
	Pack(int weight, int price) : weight(weight), price(price) {}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n, k;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> k;
		
		vector<Pack> v;
		
		for (int i = 0; i < k; ++i)
		{
			cin >> n;
			
			if (n != -1)
				v.push_back(Pack(i + 1, n));//ikg of apples costs n dollars
		}
		
		int size = int(v.size());
		
		int dp[k + 1];
		
		dp[0] = 0;
		
		for (int i = 1; i <= k; ++i)
		{
			dp[i] = INF;
			
			for (int j = 0; j < size; ++j)
				if (i - v[j].weight >= 0 && dp[i - v[j].weight] != INF)
					dp[i] = min(dp[i], v[j].price + dp[i - v[j].weight]);
		}
		
		if (dp[k] != INF)
			cout << dp[k] << "\n";
		else
			cout << "-1\n";
	}
	
	return 0;
}