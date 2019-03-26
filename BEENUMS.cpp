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
		
		bool valid = false;
		
		for (int i = 1, inc = 6; i <= n; i += inc, inc += 6)
			if (i == n)
			{
				valid = true;
				break;
			}
		
		cout << (valid ? "Y\n" : "N\n");
	}
	
	return 0;
}