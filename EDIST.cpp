#include <bits/stdc++.h>

using namespace std;

inline int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	
	string a;
	string b;
	
	cin >> T;
	cin.ignore(1, '\n');
	
	while (T--)
	{
		getline(cin, a);
		getline(cin, b);
		
		int m = a.length();
		int n = b.length();
		
		int DP[m + 1][n + 1];
		
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				if (i == 0)
				    DP[i][j] = j;
				else if (j == 0)
				    DP[i][j] = i;
				else if (a[i - 1] == b[j - 1])
				    DP[i][j] = DP[i - 1][j - 1];
				else
				    DP[i][j] = 1 + min(DP[i][j - 1], DP[i - 1][j], DP[i - 1][j - 1]);
			}
		}
		
		cout << DP[m][n] << "\n";
	}
	
	return 0;
}