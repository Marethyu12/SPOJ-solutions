#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

bool possible(ull P[], ull M[], int n, ull m, ull p)
{
	ull total = 0;
	
	for (int i = 0; i < n; ++i)
		if (P[i] < p)
			total += (p - P[i]) * M[i];
	
	return total <= m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	ull m;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> m;
		
		ull P[n];
		ull M[n];
		
		for (int i = 0; i < n; ++i)
			cin >> P[i] >> M[i];
		
		ull low = 0;
		ull high = 1000000000000LL;
		
		while (low < high)
		{
			ull mid = low + ((high - low) >> 1);
			
			if (possible(P, M, n, m, mid))
				low = mid + 1;
			else
				high = mid;
		}
		
		cout << low - 1 << "\n";
	}
	
	return 0;
}