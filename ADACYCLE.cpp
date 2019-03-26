#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> vertex;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	unordered_map<int, vector<int>> adj;
	
	cin >> N;
	
	for (int i = 1; i <= N; ++i)
	{
		vector<int> v;
		int on;
		
		for (int j = 1; j <= N; ++j)
		{
			cin >> on;
			
			if (on)
				v.push_back(j);
		}
		
		adj[i] = v;
	}
	
	for (int i = 1; i <= N; ++i)
	{
		bool m[N + 1] = {false};
		queue<vertex> q;
		
		vertex start = make_pair(i, 0);
		bool flag = false;
		int shortest = 0;
		
		m[i] = true;
		q.push(start);
		
		while (!q.empty())
		{
			vertex v = q.front();
			q.pop();
			
			if (v.first == i && v.second != 0)
			{
				flag = true;
				shortest = v.second;
				break;
			}
			
			for (int n : adj.at(v.first))
			{
				vertex s = make_pair(n, v.second + 1);
				
				if (!m[s.first] || s.first == i)
				{
					m[s.first] = true;
					q.push(s);
				}
			}
		}
		
		if (flag)
			cout << shortest << "\n";
		else
			cout << "NO WAY\n";
	}
	
	return 0;
}