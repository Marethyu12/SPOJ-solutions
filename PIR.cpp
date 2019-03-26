#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed;
	cout << setprecision(4);
	
	int T;
	
	ld u, v, w, U, V, W;
	
	cin >> T;
	
	while (T--)
	{
		cin >> w >> v >> u >> U >> V >> W;//be careful with input!
		
		ld X = (w - U + v) * (U + v + w);
		ld x = (U - v + w) * (v - w + U);
		ld Y = (u - V + w) * (V + w + u);
		ld y = (V - w + u) * (w - u + V);
		ld Z = (v - W + u) * (W + u + v);
		ld z = (W - u + v) * (u - v + W);
		
		ld a = sqrt(x * Y * Z);
		ld b = sqrt(y * Z * X);
		ld c = sqrt(z * X * Y);
		ld d = sqrt(x * y * z);
		
		ld volume = sqrt((-a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d)) / (192.0 * u * v * w);
		
		cout << volume << "\n";
	}
	
	return 0;
}