#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k;
	
	cin >> n >> k;
	
	ll height[n];
	
	for (int i = 0; i < n; ++i)
		cin >> height[i];
	
	ll low = *min_element(height, height + n);
	ll high = *max_element(height, height + n);
	
	while (low < high)
	{
		ll mid = low + ((high - low) >> 1);
		
		ll total = 0;
		
		for (int i = 0; i < n; ++i)
			if (height[i] > mid)
				total += height[i] - mid;
		
		if (total >= k)
			low = mid + 1;
		else
			high = mid;
	}
	
	cout << low - 1 << "\n";
	
	return 0;
}