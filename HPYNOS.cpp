#include <bits/stdc++.h>

using namespace std;

int iterations = 0;

int sqsum(int n)
{
	int s = 0;
	
	for (; n; n /= 10)
		s += pow(n % 10, 2);
	
	++iterations;
	
	return s;
}

bool happy(int n)
{
	unordered_map<int, int> m;
	
	while (true)
	{
		n = sqsum(n);
		
		if (n == 1)
			break;
		
		if (m.find(n) != m.end())
			return false;
		
		m[n] = 1;
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	
	cin >> N;
	
	if (happy(N))
		cout << iterations << "\n";
	else
		cout << "-1\n";
	
	return 0;
}