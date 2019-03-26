#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;
typedef pair<int, iPair> Edge;

int Find(int v, int parent[])
{
	if (v != parent[v])
		parent[v] = Find(parent[v], parent);
	
	return parent[v];
}

void Union(int u, int v, int parent[], int rank[])
{
	u = Find(u, parent);
	v = Find(v, parent);
	
	if (parent[u] == parent[v])
		return;
	
	if (rank[u] > rank[v])
		parent[v] = u;
	else if (rank[u] < rank[v])
		parent[u] = v;
	else
	{
		parent[u] = v;
		++rank[v];
	}
}

int kruskal(vector<Edge>& graph, int V, int E)
{
	int parent[V];
	int rank[V];
	
	for (int i = 0; i < V; ++i)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	
	int mst = 0;
	
	sort(graph.begin(), graph.end());
	
	for (int i = 0, edges = 0; i < E && edges < V - 1; ++i)
	{
		int u = graph[i].second.first;
		int v = graph[i].second.second;
		int weight = graph[i].first;
		
		int set_u = Find(u, parent);
		int set_v = Find(v, parent);
		
		if (set_u != set_v)
		{
			mst += weight;
			
			Union(u, v, parent, rank);
			
			++edges;
		}
	}
	
	return mst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int V, E;
	int u, v, weight;
	
	while (true)
	{
		cin >> V >> E;
		
		if (V == 0 && E == 0)
			break;
		
		vector<Edge> graph;
		
		int total = 0;
		
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v >> weight;
			
			graph.push_back(make_pair(weight, make_pair(u, v)));
			
			total += weight;
		}
		
		cout << (total - kruskal(graph, V, E)) << "\n";
	}
	
	return 0;
}