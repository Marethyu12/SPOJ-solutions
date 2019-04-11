#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed;
	cout << setprecision(2);
	
	int T;
	
	ld a, b, c, d;
	
	cin >> T;
	
	while (T--)
	{
		cin >> a >> b >> c >> d;
		
		ld K = sqrt((-a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d)) / 4.0;
		
		cout << K << "\n";
	}
	
	return 0;
}