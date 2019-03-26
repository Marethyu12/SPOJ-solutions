#include <bits/stdc++.h>

using namespace std;

inline int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

string lcs(const string& a, const string& b)
{
	int m = a.length();
	int n = b.length();
	
	int dp[m + 1][n + 1];
	
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	
	int index = dp[m][n];
	
	char buf[index + 1];
	
	buf[index] = '\0';
	
	int i = m;
	int j = n;
	
	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			buf[--index] = a[i - 1];
			--i;
			--j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			--i;
		else
			--j;
	}
	
	return string(buf);
}

int edit_dist(const string& a, const string& b)
{
	int m = a.length();
	int n = b.length();
	
	int dp[m + 1][n + 1];
	
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);//min of insert, delete, replace
		}
	
	return dp[m][n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	
	string s;
	
	cin >> T;
	cin.ignore(1, '\n');
	
	while (T--)
	{
		getline(cin, s);
		
		//note: lps(string) = lcs(string, reverse(string))
		cout << edit_dist(s, lcs(s, string(s.rbegin(), s.rend()))) << "\n";
	}
	
	return 0;
}