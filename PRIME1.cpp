#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
	if (n == 1)
		return false;
	
	if (n == 2)
		return true;
	
	if (n % 2 == 0)
		return false;
	
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int low, high;
	
	cin >> T;
	
	while (T--)
	{
		cin >> low >> high;
		
		for (int i = low; i <= high; ++i)
			if (prime(i))
				cout << i << "\n";
		
		cout << "\n";
	}
	
	return 0;
}