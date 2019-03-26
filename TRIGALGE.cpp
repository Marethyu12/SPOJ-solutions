#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

int a;
int b;
int c;

inline double f(double x)
{
	return a * x + b * sin(x) - c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed;
	cout << setprecision(6);
	
	int T;
	
	cin >> T;
	
	while (T--)
	{
		cin >> a >> b >> c;
		
		double l = -100000.0;
		double r = 100000.0;
		
		while (r - l > eps)
		{
			double m = l + (r - l) / 2.0;
			
			if (f(l) * f(m) < 0.0)
				r = m;
			else
				l = m;
		}
		
		cout << l << "\n";
	}
	
	return 0;
}