/*
 * With pencil and paper, the formula
 * for sum of all subsequences of an array
 * is (2^(n - 1)) * (sigma(a[i]) for i from 0 to n - 1).
 */
#include <bits/stdc++.h>

using namespace std;

const int mod = 100000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	int x;
	
	int cn = 1;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		int total = 0;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			
			total = (total + (x % mod)) % mod;
		}
		
		int factor = 1;
		
		for (int i = 0; i < n - 1; ++i)
			factor = ((long long int) factor * 2) % mod;
		
		total = ((long long int) total * factor) % mod;
		
		cout << "Case " << cn++ << ": " << total << "\n";
	}
	
	return 0;
}