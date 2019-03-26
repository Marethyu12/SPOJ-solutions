#include <bits/stdc++.h>

using namespace std;

bool dfs(int vertex, int parent, bool visited[], vector<int> adj[])
{
	visited[vertex] = true;
	
	for (int successor : adj[vertex])
		if (!visited[successor])
		{
			if (dfs(successor, vertex, visited, adj))
				return true;
		}
		else if (successor != parent)//undirected graph has cycle if already visited vertex != its parent
			return true;
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int V, E;
	int u, v;
	
	cin >> V >> E;
	
	vector<int> adj[V];
	
	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v;
		
		--u;
		--v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool visited[V] = {false};
	bool tree = true; /* Tree is undirectedm connected, and acyclic graph */
	
	for (int i = 0; i < V; ++i)
		if (!visited[i])
			if (dfs(i, -1, visited, adj))
			{
				tree = false;
				break;
			}
	
	tree = tree && all_of(visited, visited + V, [](const bool& a)
	{
		return a;
	});
	
	cout << (tree ? "YES\n" : "NO\n");
	
	return 0;
}