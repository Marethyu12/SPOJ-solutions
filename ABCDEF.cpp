#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	cin >> n;
	
	int s[n];
	
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	
	vector<int> left;
	
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < n; ++b)
			for (int c = 0; c < n; ++c)
				left.push_back(s[a] * s[b] + s[c]);
	
	sort(left.begin(), left.end());
	
	int solutions = 0;
	
	for (int d = 0; d < n; ++d)
	{
		if (s[d] == 0)
			continue;
		
		for (int e = 0; e < n; ++e)
			for (int f = 0; f < n; ++f)
			{
				int rhs = s[d] * (s[e] + s[f]);
				
				solutions += upper_bound(left.begin(), left.end(), rhs) - lower_bound(left.begin(), left.end(), rhs);
			}
	}
	
	cout << solutions << "\n";
	
	return 0;
}