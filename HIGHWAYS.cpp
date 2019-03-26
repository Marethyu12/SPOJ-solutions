#include <bits/stdc++.h>

#define INF 0x3F3F3F3F

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int V, E;
	int source, destination;
	int u, v, weight;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V >> E >> source >> destination;
		
		--source;
		--destination;
		
		vector<pair<int, int>> adj[V];
		
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v >> weight;
			
			--u;
			--v;
			
			adj[u].push_back(make_pair(v, weight));
			adj[v].push_back(make_pair(u, weight));
		}
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> dist(V, INF);
		
		pq.push(make_pair(0, source));
		dist[source] = 0;
		
		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();
			
			for (auto iter = adj[u].begin(); iter != adj[u].end(); ++iter)
			{
				int v = iter->first;
				int weight = iter->second;
				
				if (dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
		
		if (dist[destination] == INF)
			cout << "NONE\n";
		else
			cout << dist[destination] << "\n";
	}
	
	return 0;
}