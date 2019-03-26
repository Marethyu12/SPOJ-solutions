#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		int nums[n];
		
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		
		if (next_permutation(nums, nums + n))
			for (int i = 0; i < n; ++i)
				cout << nums[i];
		else
			cout << "-1";
		
		cout << "\n";
	}
	
	return 0;
}