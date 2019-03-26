#include <bits/stdc++.h>

#define MAXN 1000000000

using namespace std;

bool place(int stalls[], int n, int dist, int c)
{
	int pos = stalls[0];
	int i = 1;
	
	for (int cow = 1; cow < c; ++cow)
	{
		while (i < n && pos + dist > stalls[i])
			++i;
		
		if (i == n)
			return false;
		
		pos = stalls[i];
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n, c;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> c;
		
		int stalls[n];
		
		for (int i = 0; i < n; ++i)
			cin >> stalls[i];
		
		sort(stalls, stalls + n);
		
		int low = 0;
		int high = MAXN + 1;
		
		while (low < high)
		{
			int mid = low + ((high - low) >> 1);
			
			if (place(stalls, n, mid, c))
				low = mid + 1;
			else
				high = mid;
		}
		
		cout << low - 1 << "\n";
	}
	
	return 0;
}