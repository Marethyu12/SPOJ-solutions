#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a1, a2, a3;
	
	for (;;)
	{
		cin >> a1 >> a2 >> a3;
		
		if (a1 == 0 && a2 == 0 && a3 == 0)
			break;
		
		if (a2 - a1 == a3 - a2)
		{
			int diff = a2 - a1;
			
			cout << "AP " << (a3 + diff) << "\n";
		}
		else
		{
			int ratio = a2 / a1;
			
			cout << "GP " << (a3 * ratio) << "\n";
		}
	}
	
	return 0;
}