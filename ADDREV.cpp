#include <bits/stdc++.h>

using namespace std;

int rev(int n)
{
	string s = "";
	
	for (; n; n /= 10)
		s += to_string(n % 10);
	
	int i = 0;
	int j = s.length();
	
	while (s[i] == '0')
		++i;
	
	while (s[j] == '0')
		--j;
	
	return stoi(s.substr(i, j + 1));
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
		
		cout << rev(rev(a) + rev(b)) << "\n";
	}
	
	return 0;
}