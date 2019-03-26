#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	unsigned long long int n;
	
	cin >> n;
	
	unordered_set<unsigned long long int> s;
	
	bool infloop = false;
	
	while (n > 1)
	{
		if (s.find(n) == s.end())
			s.insert(n);
		else
		{
			infloop = true;
			break;
		}
		
		if (n % 2 == 0)
			n >>= 1;
		else
			n = 3 * n + 3;
	}
	
	if (infloop)
		cout << "NIE\n";
	else
		cout << "TAK\n";
	
	return 0;
}