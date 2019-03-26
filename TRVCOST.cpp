#include <bits/stdc++.h>

#define MAXN 1010
#define INF 0x3F3F3F3F

using namespace std;

typedef pair<int, int> pii;

void addEdge(vector<pii> adj[], int u, int v, int weight)
{
	adj[u].push_back(make_pair(v, weight));
	adj[v].push_back(make_pair(u, weight));
}

vector<int> dijkstra(vector<pii> adj[], int V, int src)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(V + 1, INF);
	
	pq.push(make_pair(0, src));
	dist[src] = 0;
	
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		
		for (const pii& neighbour : adj[u])
		{
			int v = neighbour.first;
			int weight = neighbour.second;
			
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	
	return dist;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int A, B, W;
	int U;
	int Q;
	int V;
	
	cin >> N;
	
	vector<pii> adj[MAXN];
	
	for (int i = 0; i < N; ++i)
	{
		cin >> A >> B >> W;
		addEdge(adj, A, B, W);
	}
	
	vector<int> querys;
	
	cin >> U;
	cin >> Q;
	
	for (int i = 0; i < Q; ++i)
	{
		cin >> V;
		querys.push_back(V);
	}
	
	vector<int> dist = dijkstra(adj, MAXN, U);
	
	for (int query : querys)
		if (dist[query] == INF)
			cout << "NO PATH\n";
		else
			cout << dist[query] << "\n";
	
	return 0;
}