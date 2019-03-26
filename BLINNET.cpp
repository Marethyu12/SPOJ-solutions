#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int u;
	int v;
	int weight;
	
	Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
	
	bool operator<(const Edge& that)
	{
		return this->weight < that.weight;
	}
};

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
	else if (parent[u] < parent[v])
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
	
	sort(graph.begin(), graph.end());
	
	int mst = 0;
	
	for (int i = 0, edges = 0; i < E && edges < V - 1; ++i)
	{
		int u = graph[i].u;
		int v = graph[i].v;
		int weight = graph[i].weight;
		
		int set_u = Find(u, parent);
		int set_v = Find(v, parent);
		
		if (set_u != set_v)
		{
			Union(set_u, set_v, parent, rank);
			
			mst += weight;
		}
	}
	
	return mst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int V, E;
	
	string s;
	
	int degree;
	int v, weight;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V;
		
		E = 0;
		
		vector<Edge> graph;
		
		for (int u = 0; u < V; ++u)
		{
			cin >> s;
			cin >> degree;
			
			for (int j = 0; j < degree; ++j)
			{
				cin >> v >> weight;
				
				--v;
				
				if (u < v)
				{
					graph.push_back(Edge(u, v, weight));
					
					++E;
				}
			}
		}
		
		cout << kruskal(graph, V, E) << "\n";
	}
	
	return 0;
}