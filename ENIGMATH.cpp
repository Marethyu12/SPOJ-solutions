#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	if (b == 0)
		return a;
	
	return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	
	long long int a, b;
	
	cin >> T;
	
	while (T--)
	{
		cin >> a >> b;
		
		long long int m = lcm(a, b);
		
		cout << (m / a) << " " << (m / b) << "\n";
	}
	
	return 0;
}