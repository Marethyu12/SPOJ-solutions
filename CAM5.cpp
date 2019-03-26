#include <bits/stdc++.h>

using namespace std;

void dfs(int vertex, bool visited[], vector<int> adj[])
{
	visited[vertex] = true;
	
	for (int successor : adj[vertex])
		if (!visited[successor])
			dfs(successor, visited, adj);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int N;
	int e;
	int a, b;
	
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		cin >> e;
		
		vector<int> adj[N];
		
		for (int i = 0; i < e; ++i)
		{
			cin >> a >> b;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		bool visited[N] = {false};
		
		int connected_components = 0;
		
		for (int i = 0; i < N; ++i)
			if (!visited[i])
			{
				dfs(i, visited, adj);
				connected_components++;
			}
		
		cout << connected_components << "\n";
	}
	
	return 0;
}