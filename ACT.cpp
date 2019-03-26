#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	string s;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> s;
		
		cout << s[s.length() - 1] << "\n";
	}
	
	return 0;
}