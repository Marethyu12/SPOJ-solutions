#include <bits/stdc++.h>

using namespace std;

vector<int> tokenize(const string& s)
{
	stringstream ss(s);
	string tmp;
	
	vector<int> v;
	
	while (getline(ss, tmp, ' '))
	{
		int x = stoi(tmp);
		
		if (x != 0)
			v.push_back(x);
	}
	
	return v;
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
		
		vector<int> a = tokenize(s);
		
		vector<vector<int>> seqs;
		
		while (true)
		{
			getline(cin, s);
			
			if (s == "0")
				break;
			
			seqs.push_back(tokenize(s));
		}
		
		int longest = 0;
		
		for (const vector<int>& b : seqs)
		{
			int m = int(a.size());
			int n = int(b.size());
			
			vector<vector<int>> dp(m + 1, vector<int>(n + 1));
			
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
			
			longest = max(longest, dp[m][n]);
		}
		
		cout << longest << "\n";
	}
	
	return 0;
}