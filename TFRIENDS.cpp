#include <bits/stdc++.h>

using namespace std;

void toposort(int u, bool visited[], vector<int> adj[], stack<int>& s)
{
	visited[u] = true;
	
	for (int v : adj[u])
		if (!visited[v])
			toposort(v, visited, adj, s);
	
	s.push(u);
}

void dfs(int u, bool visited[], vector<int> adj[])
{
	visited[u] = true;
	
	for (int v : adj[u])
		if (!visited[v])
			dfs(v, visited, adj);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int V;
	
	string s;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V;
		cin.ignore(1, '\n');
		
		vector<int> adj[V];
		
		for (int u = 0; u < V; ++u)
		{
			getline(cin, s);
			
			for (int v = 0; v < V; ++v)
				if (s[v] == 'Y')
					adj[u].push_back(v);
		}
		
		bool visited[V] = {false};
		
		stack<int> s;
		
		for (int i = 0; i < V; ++i)
			if (!visited[i])
				toposort(i, visited, adj, s);
		
		memset(visited, false, sizeof(visited));
		
		vector<int> gT[V];
		
		for (int u = 0; u < V; ++u)
			for (int v : adj[u])
				gT[v].push_back(u);
		
		int sccs = 0;
		
		while (!s.empty())
		{
			int u = s.top();
			s.pop();
			
			if (!visited[u])
			{
				dfs(u, visited, gT);
				++sccs;
			}
		}
		
		cout << sccs << "\n";
	}
	
	return 0;
}