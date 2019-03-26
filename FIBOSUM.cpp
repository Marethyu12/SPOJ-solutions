#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<vector<ll>> matrix;

const ll mod = (ll) 1e9 + 7;

matrix multiply(const matrix& a, const matrix& b)
{
	int rows = (int) a.size();
	int cols = (int) b[0].size();
	int n = (int) b.size();
	
	matrix mat(rows, vector<ll>(cols, 0));
	
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			for (int k = 0; k < n; ++k)
			{
				mat[i][j] += ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
				mat[i][j] %= mod;
			}
	
	return mat;
}

matrix power(const matrix& mat, int x)
{
	if (x == 1)
		return mat;
	
	matrix res = power(mat, x / 2);
	
	if (x % 2 == 0)
		return multiply(res, res);
	
	return multiply(multiply(res, res), mat);
}

int fib(int n)
{
	if (n == 0)
		return 0;
	
	matrix F(2, vector<ll>(1));
	matrix X(2, vector<ll>(2));
	
	F[0][0] = 0;
	F[1][0] = 1;
	
	X[0][0] = 0;
	X[0][1] = 1;
	X[1][0] = 1;
	X[1][1] = 1;
	
	matrix F1 = multiply(power(X, n), F);
	
	return F1[0][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int a, b;
	
	cin >> T;
	
	while (T--)
	{
		cin >> a >> b;
		
		ll res = fib(b + 2) - fib(a + 1);
		
		if (res < 0)
			res += mod;
		
		cout << res << "\n";
	}
	
	return 0;
}