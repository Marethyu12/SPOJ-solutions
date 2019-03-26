#include <bits/stdc++.h>

#define INF 0x3F3F3F3F

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int s;
	int n;
	string name;
	int p;
	int connect, cost;
	int r;
	string from, to;
	
	cin >> s;
	
	while (s--)
	{
		cin >> n;
		
		unordered_map<string, int> dict;
		vector<pair<int, int>> adj[n + 1];
		
		for (int i = 1; i <= n; ++i)
		{
			cin.ignore(1, '\n');
			getline(cin, name);
			
			dict[name] = i;
			
			cin >> p;
			
			for (int j = 0; j < p; ++j)
			{
				cin >> connect >> cost;
				
				adj[i].push_back(make_pair(connect, cost));
				//adj[connect].push_back(make_pair(i, cost));
			}
		}
		
		cin >> r;
		cin.ignore(1, '\n');
		
		for (int i = 0; i < r; ++i)
		{
			cin >> from >> to;
			
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			vector<int> dist(n + 1, INF);
			
			pq.push(make_pair(0, dict[from]));
			dist[dict[from]] = 0;
			
			while (!pq.empty())
			{
				int u = pq.top().second;
				pq.pop();
				
				for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
				{
					int v = it->first;
					int w = it->second;
					
					if (dist[v] > dist[u] + w)
					{
						dist[v] = dist[u] + w;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
			
			cout << dist[dict[to]] << "\n";
		}
	}
	
	return 0;
}