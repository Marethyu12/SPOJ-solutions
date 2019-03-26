#include <bits/stdc++.h>

using namespace std;

vector<int> buildLPS(const string& pat)
{
	int m = int(pat.length());
	
	vector<int> lps(m);
	
	int len = 0;
	
	lps[0] = 0;
	
	int i = 1;
	
	while (i < m)
	{
		if (pat[i] == pat[len])
			lps[i++] = ++len;
		else
		{
			if (len != 0)
				len = lps[len - 1];
			else
				lps[i++] = 0;
		}
	}
	
	return lps;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	string pat;
	string txt;
	
	int cn = 1;
	
	while (cin >> n)
	{
		cin.ignore(1, '\n');
		
		getline(cin, pat);
		getline(cin, txt);
		
		if (cn++ > 1)
			cout << "\n";
		
		int m = int(pat.length());
		int n = int(txt.length());
		
		vector<int> lps = buildLPS(pat);
		
		int i = 0;
		int j = 0;
		
		while (i < n)
		{
			if (pat[j] == txt[i])
			{
				++i;
				++j;
			}
			
			if (j == m)
			{
				cout << i - j << "\n";
				
				j = lps[j - 1];
			}
			else if (i < n && pat[j] != txt[i])
			{
				if (j != 0)
					j = lps[j - 1];
				else
					++i;
			}
		}
	}
	
	return 0;
}