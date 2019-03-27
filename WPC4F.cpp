#include <bits/stdc++.h>

#define INF 0x7FFFFFFF

using namespace std;

int jump(int cost[][3], int n, int state)
{
	if (n == 0)
		return 0;
	
	int q = INF;
	
	for (int i = 0; i < 3; ++i)
		if (i != state)
			q = min(q, cost[n - 1][i] + jump(cost, n - 1, i));
	
	return q;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	int a, b, c;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		int cost[n][3];
		
		for (int i = 0; i < n; ++i)
			cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		
		cout << jump(cost, n, -1) << "\n";
	}
	
	return 0;
}