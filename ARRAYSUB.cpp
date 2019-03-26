#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int k;
	
	cin >> n;
	
	int nums[n];
	
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	
	cin >> k;
	
	for (int i = 0; i < n - k + 1; ++i)
	{
		int m = 0;
		
		for (int j = 0; j < k; ++j)
			m = max(m, nums[i + j]);
		
		cout << m << " ";
	}
	
	return 0;
}