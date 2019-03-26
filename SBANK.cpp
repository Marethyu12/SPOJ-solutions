#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	string s;
	
	int cn = 1;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		cin.ignore(1, '\n');
		
		map<string, int> msi;
		
		for (int i = 0; i < n; ++i)
		{
			getline(cin, s);
			msi[s]++;
		}
		
		if (cn++ > 1)
			cout << "\n";
		
		for (auto iter = msi.begin(); iter != msi.end(); ++iter)
			cout << iter->first << " " << iter->second << "\n";
	}
	
	return 0;
}