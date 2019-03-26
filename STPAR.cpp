#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	while (true)
	{
		cin >> n;
		
		if (n == 0)
			break;
		
		int order[n];
		
		for (int i = 0; i < n; ++i)
			cin >> order[i];
		
		stack<int> lane;
		
		bool possible = true;
		int want = 1;
		
		for (int i = 0; i < n; ++i)
		{
			int truck = order[i];
			
			while (!lane.empty() && lane.top() == want)//truck at back of lane is desired
			{
				want++;
				lane.pop();
			}
			
			if (truck == want)
				want++;//go to destination
			else if (!lane.empty() && lane.top() < want)//why?!?
			{
				possible = false;
				break;
			}
			else
				lane.push(truck);
		}
		
		cout << (possible ? "yes\n" : "no\n");
	}
	
	return 0;
}