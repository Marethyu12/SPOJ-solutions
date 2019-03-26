#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	
	cin >> n >> k;
	
	int nums[n];
	
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	
	sort(nums, nums + n);
	
	int c = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int low = 0;
		int high = n - 1;
		int val = nums[i] + k;
		
		if (val > nums[n - 1])
			break;
		
		while (low <= high)
		{
			int mid = low + ((high - low) >> 1);
			
			if (nums[mid] == val)
			{
				c++;
				break;
			}
			
			if (nums[mid] < val)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	
	cout << c << "\n";
	
	return 0;
}