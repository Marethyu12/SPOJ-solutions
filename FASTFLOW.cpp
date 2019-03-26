#include <bits/stdc++.h>

#define INF 0x7FFFFFFF

using namespace std;

class FlowNetwork
{
private:
	struct Edge
	{
		int v;
		int flow;
		int cap;
		int rev;
		
		Edge(int v, int flow, int cap, int rev) : v(v), flow(flow), cap(cap), rev(rev) {}
	};
	
	int V;
	
	vector<int> level;
	vector<vector<Edge>> adj;
	
	bool bfs(int s, int t);
	int sendFlow(int s, int t, int flow, int next[]);
public:
	FlowNetwork(int V);
	void addDirectedEdge(int u, int v, int cap);
	long long int maxFlow(int s, int t);
};

bool FlowNetwork::bfs(int s, int t)
{
	bool visited[V] = {false};
	queue<int> q;
	
	visited[s] = true;
	level[s] = 0;
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for (const Edge& edge : adj[u])
		{
			int v = edge.v;
			int flow = edge.flow;
			int cap = edge.cap;
			
			if (!visited[v] && flow < cap)
			{
				visited[v] = true;
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	
	return visited[t];
}

int FlowNetwork::sendFlow(int s, int t, int flow, int next[])
{
	if (s == t)
		return flow;
	
	for (int size = adj[s].size(); next[s] < size; ++next[s])
	{
		Edge& edge = adj[s][next[s]];
		
		int v = edge.v;
		int cap = edge.cap;
		int rev = edge.rev;
		
		if (level[v] == level[s] + 1 && edge.flow < cap)
		{
			int cur_flow = min(flow, cap - edge.flow);
			int tmp_flow = sendFlow(v, t, cur_flow, next);
			
			if (tmp_flow > 0)
			{
				edge.flow += tmp_flow;
				adj[v][rev].flow -= tmp_flow;
				
				return tmp_flow;
			}
		}
	}
	
	return 0;
}

FlowNetwork::FlowNetwork(int V)
{
	this->V = V;
	
	level.resize(V);
	adj.assign(V, vector<Edge>());
}

void FlowNetwork::addDirectedEdge(int u, int v, int cap)
{
	Edge forward_edge(v, 0, cap, int(adj[v].size()));
	Edge back_edge(u, 0, 0, int(adj[u].size()));
	
	adj[u].push_back(forward_edge);
	adj[v].push_back(back_edge);
}

long long int FlowNetwork::maxFlow(int s, int t)
{
	if (s == t)
		return -1;
	
	long long int m_flow = 0;
	
	while (bfs(s, t))
	{
		int next[V];
		long long int flow = 0;
		
		memset(next, 0, sizeof(next));
		
		while ((flow = sendFlow(s, t, INF, next)) != 0)
			m_flow += flow;
	}
	
	return m_flow;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int V, E;
	int u, v, cap;
	
	cin >> V >> E;
	
	FlowNetwork g(V);
	
	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> cap;
		
		--u;
		--v;
		
		g.addDirectedEdge(u, v, cap);
		g.addDirectedEdge(v, u, cap);
	}
	
	cout << g.maxFlow(0, V - 1) << "\n";
	
	return 0;
}