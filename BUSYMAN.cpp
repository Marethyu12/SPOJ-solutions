#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int N;
	int a, b;
	
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		
		vector<pair<int, int>> v;
		
		for (int i = 0; i < N; ++i)
		{
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		
		sort(v.begin(), v.end(), [](const auto& a, const auto& b)
		{
			if (a.second == b.second)
				return a.first < b.first;
			
			return a.second < b.second;//sort based on end times
		});
		
		int max_activities = 1;
		
		int prev = 0;
		
		for (int i = 1; i < N; ++i)
		{
			if (v[i].first >= v[prev].second)
			{
				max_activities++;
				prev = i;
			}
		}
		
		cout << max_activities << "\n";
	}
	
	return 0;
}