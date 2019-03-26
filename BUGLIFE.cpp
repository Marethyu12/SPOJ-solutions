#include <bits/stdc++.h>

#define MAXN 2000

using namespace std;

vector<int> adj[MAXN + 1];
bool visited[MAXN + 1];
int color[MAXN + 1];

bool biparitate;

void addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(int source)
{
	queue<int> q;
	
	visited[source] = true;
	color[source] = 0;
	q.push(source);
	
	while (!q.empty())
	{
	    int v = q.front();
	    q.pop();
	    
	    for (int s : adj[v])
	    {
	        if (color[s] == color[v])
	        {
	            biparitate = false;
	            return;
	        }
	        
	        color[s] = color[v] == 1 ? 0 : 1;
	        
	        if (!visited[s])
	        {
	            visited[s] = true;
	            q.push(s);
	        }
	    }
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int V, E;
	int u, v;
	
	cin >> T;
	
	for (int i = 1; i <= T; ++i)
	{
		cin >> V >> E;
		
		for (int i = 1; i <= V; ++i)
		{
		    adj[i].clear();
		    visited[i] = false;
		    color[i] = -1;
		}
		
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v;
			addEdge(u, v);
		}
		
		biparitate = true;
		
		for (int i = 1; i <= V && biparitate; ++i)
		    if (!visited[i])
		        bfs(i);
		
		if (biparitate)
			cout << "Scenario #" << i << ":\n" << "No suspicious bugs found!\n";
		else
			cout << "Scenario #" << i << ":\n" << "Suspicious bugs found!\n";
	}
	
	return 0;
}