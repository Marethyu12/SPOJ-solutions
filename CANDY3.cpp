#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	long long int amt;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		long long int total = 0;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> amt;
			total = (total + amt) % n;
		}
		
		if (total == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}