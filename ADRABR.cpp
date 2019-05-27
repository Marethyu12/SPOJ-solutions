#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	int V, E;
	int s, t;
	int u, v;
	
	ll weight;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V >> E >> s >> t;
		
		--s, --t;
		
		vector<pair<int, ll>> adj[V];
		
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v >> weight;
			
			--u, --v;
			weight += 12;
			
			adj[u].push_back(make_pair(v, weight));
			adj[v].push_back(make_pair(u, weight));
		}
		
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		vector<ll> dist(V, numeric_limits<ll>::max());
		
		pq.push(make_pair(0, s));
		dist[s] = 0;
		
		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();
			
			for (auto iter = adj[u].begin(), stop = adj[u].end(); iter != stop; ++iter)
			{
				int v = iter->first;
				
				ll weight = iter->second;
				
				if (dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
		
		cout << dist[t] << "\n";
	}
	
	return 0;
}