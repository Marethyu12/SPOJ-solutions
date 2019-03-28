#include <bits/stdc++.h>

using namespace std;

vector<int> buildLPS(const string& pat)
{
	int m = (int) pat.length();
	
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

vector<int> KMP(const string& pat, const string& txt)
{
	vector<int> pos;
	
	int m = (int) pat.length();
	int n = (int) txt.length();
	
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
			pos.push_back(i - j + 1);
			
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
	
	return pos;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int cn = 1;
	
	string txt, pat;
	
	cin >> T;
	cin.ignore(1, '\n');
	
	while (T--)
	{
		cin >> txt >> pat;
		
		vector<int> pos = KMP(pat, txt);
		
		if (cn++ > 1)
			cout << "\n";
		
		int size = (int) pos.size();
		
		if (size == 0)
			cout << "Not Found\n";
		else
		{
			cout << size << "\n";
			
			for (int i = 0; i < size; ++i)
				cout << pos[i] << " \n"[i == size - 1];
		}
	}
	
	return 0;
}