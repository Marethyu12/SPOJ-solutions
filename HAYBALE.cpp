#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	int a, b;
	
	cin >> n >> k;
	
	int diff[n];
	
	memset(diff, 0, sizeof(diff));
	
	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b;
		
		diff[a - 1]++;
		diff[b]--;
	}
	
	int nums[n];
	
	nums[0] = diff[0];
	
	for (int i = 1; i < n; ++i)
		nums[i] = nums[i - 1] + diff[i];
	
	sort(nums, nums + n);
	
	cout << nums[n / 2] << "\n";
	
	return 0;
}