#include <bits/stdc++.h>

#define MAXN 10001

using namespace std;

typedef long long ll;

int N;

ll heights[MAXN];
ll costs[MAXN];

ll predicate(ll height)
{
	ll cost = 0;
	
	for (int i = 0; i < N; ++i)
		cost += abs(heights[i] - height) * costs[i];
	
	return cost;
}

ll ternary_search(ll low, ll high)
{
	while (low < high)
	{
		ll m1 = low + (high - low) / 3;
		ll m2 = high - (high - low) / 3;
		
		ll f1 = predicate(m1);
		ll f2 = predicate(m2);
		
		if (f1 > f2)
			low = m1 + 1;
		else
			high = m2 - 1;
	}
	
	return predicate(low);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		
		for (int i = 0; i < N; ++i)
			cin >> heights[i];
		
		for (int i = 0; i < N; ++i)
			cin >> costs[i];
		
		cout << ternary_search(0, MAXN) << "\n";
	}
	
	return 0;
}