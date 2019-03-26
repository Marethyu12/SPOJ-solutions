#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n, u;
	int l, r, val;
	int q;
	int ind;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> u;
		
		int diff[n + 1];//extra space for update operation
		
		memset(diff, 0, sizeof(diff));
		
		for (int ui = 0; ui < u; ++ui)
		{
			cin >> l >> r >> val;
			
			diff[l] += val;
			diff[r + 1] -= val;
		}
		
		int nums[n];
		
		nums[0] = diff[0];
		
		for (int i = 1; i < n; ++i)
			nums[i] = nums[i - 1] + diff[i];
		
		cin >> q;
		
		for (int qi = 0; qi < q; ++qi)
		{
			cin >> ind;
			
			cout << nums[ind] << "\n";
		}
	}
	
	return 0;
}