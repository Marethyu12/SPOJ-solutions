#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	long _start = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int N;
	
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		
		int count = 0;
		
		for (int i = 5; (N / i) > 0; i *= 5)
			count += (N / i);
		
		cout << count << "\n";
	}
	
#ifndef ONLINE_JUDGE
    cout << "\nprocess terminated in " << (clock() - _start) << "ms\n";
#endif
	return 0;
}