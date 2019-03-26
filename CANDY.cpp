#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	while (true)
	{
		cin >> n;
		
		if (n == -1)
			break;
		
		int nums[n];
		int total = 0;
		
		for (int i = 0; i < n; total += nums[i++])
			cin >> nums[i];
		
		double share = double(total) / double(n);
		
		if (floor(share) == ceil(share))
		{
			int moves = 0;
			
			for (int i = 0; i < n; ++i)
				if (int(share) > nums[i])
					moves += int(share) - nums[i];
			
			cout << moves << "\n";
		}
		else
			cout << "-1\n";
	}
	
	return 0;
}