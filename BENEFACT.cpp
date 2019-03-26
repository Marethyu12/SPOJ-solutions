#include <bits/stdc++.h>

#define MAXN 50001

using namespace std;

int best;
int end_vertex;

void dfs(int vertex, bool visited[], vector<pair<int, int>> adj[], int dist)
{
	visited[vertex] = true;
	
	for (const pair<int, int>& successor : adj[vertex])
		if (!visited[successor.first])
			dfs(successor.first, visited, adj, dist + successor.second);
	
	visited[vertex] = false;
	
	if (best < dist)
	{
		best = dist;
		end_vertex = vertex;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int N;
	int u, v, weight;
	
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		
		vector<pair<int, int>> adj[MAXN];
		
		for (int i = 1; i < N; ++i)
		{
			cin >> u >> v >> weight;
			adj[u].push_back(make_pair(v, weight));
			adj[v].push_back(make_pair(u, weight));
		}
		
		best = 0;
		
		bool visited[MAXN] = {false};
		
		dfs(1, visited, adj, 0);
		dfs(end_vertex, visited, adj, 0);
		
		cout << best << "\n";
	}
	
	return 0;
}