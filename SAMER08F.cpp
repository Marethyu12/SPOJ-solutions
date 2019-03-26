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
		
		if (n == 0)
			break;
		
		int ans = n * (n + 1) * (2 * n + 1) / 6;
		
		cout << ans << "\n";
	}
	
	return 0;
}