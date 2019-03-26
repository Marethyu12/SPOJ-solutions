/*
Key points:
-every citizen is connected to at least one milkman (if a set does not have a milkman and other have one, unite)
-milkmen does not need to go to some other milkmen for milk (if both sets have a milkman, don't unite)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Edge
{
	int u;
	int v;
	
	ll weight;
	
	Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
	
	bool operator<(const Edge& other)
	{
		return weight < other.weight;
	}
};

class DSU
{
private:
	vector<int> parent;
	vector<int> rank;
	vector<bool> hasMilkman;
public:
	DSU(int sets)
	{
		parent.resize(sets);
		rank.resize(sets);
		hasMilkman.resize(sets);
		
		for (int i = 0; i < sets; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
			hasMilkman[i] = false;
		}
	}
	
	int Find(int v)
	{
		if (v != parent[v])
			parent[v] = Find(parent[v]);
		
		return parent[v];
	}
	
	bool Union(int u, int v)
	{
		u = Find(u);
		v = Find(v);
		
		if (parent[u] == parent[v] || (HasMilkman(u) && HasMilkman(v)))
			return false;
		
		if (rank[u] > rank[v])
		{
			parent[v] = u;
			hasMilkman[u] = hasMilkman[u] or hasMilkman[v];
		}
		else if (rank[u] < rank[v])
		{
			parent[u] = v;
			hasMilkman[v] = hasMilkman[v] or hasMilkman[u];
		}
		else
		{
			parent[u] = v;
			hasMilkman[v] = hasMilkman[v] or hasMilkman[u];
			++rank[v];
		}
		
		return true;
	}
	
	void SetMilkman(int v)
	{
		hasMilkman[Find(v)] = true;
	}
	
	bool HasMilkman(int v)
	{
		return hasMilkman[Find(v)];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int V, E;
	
	bool b;
	
	int u, v;
	
	ll weight;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V >> E;
		
		vector<Edge> graph;
		DSU dsu(V);
		
		for (int i = 0; i < V; ++i)
		{
			cin >> b;
			
			if (b)
				dsu.SetMilkman(i);
		}
		
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v >> weight;
			
			--u;
			--v;
			
			graph.push_back(Edge(u, v, weight));
		}
		
		sort(graph.begin(), graph.end());
		
		ll mst = 0;
		
		for (int i = 0, size = int(graph.size()), edges = 0; i < size && edges < V - 1; ++i)
		{
			int u = graph[i].u;
			int v = graph[i].v;
			
			ll weight = graph[i].weight;
			
			if (dsu.Union(u, v))
			{
				mst += weight;
				
				++edges;
			}
		}
		
		bool ok = true;
		
		for (int i = 0; i < V; ++i)//make sure everybody have an access to milk
			if (!dsu.HasMilkman(i))
			{
				ok = false;
				break;
			}
		
		if (!ok)
			cout << "impossible\n";
		else
			cout << mst << "\n";
	}
	
	return 0;
}