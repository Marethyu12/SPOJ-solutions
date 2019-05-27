#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

struct Edge
{
	int u;
	int v;
	
	ull weight;
	
	Edge(int u, int v, ull weight) : u(u), v(v), weight(weight) {}
	
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
public:
	DSU(int sets)
	{
		parent.resize(sets);
		rank.resize(sets);
		
		for (int i = 0; i < sets; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
	
	int Find(int x)
	{
		if (x != parent[x])
			parent[x] = Find(parent[x]);
		
		return parent[x];
	}
	
	bool Union(int x, int y)
	{
		x = Find(x);
		y = Find(y);
		
		if (parent[x] == parent[y])
			return false;
		
		if (rank[x] > rank[y])
			parent[y] = x;
		else if (rank[x] < rank[y])
			parent[x] = y;
		else
		{
			parent[x] = y;
			rank[x]++;
		}
		
		return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	int V, E;
	int u, v;
	
	ull weight;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V >> E;
		
		vector<Edge> edges;
		
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v >> weight;
			
			--u, --v;
			
			edges.push_back(Edge(u, v, weight));
		}
		
		sort(edges.begin(), edges.end());
		
		DSU dsu(V);
		
		int divisors = 0;
		
		for (int i = 0, j = 0; i < E && j < V - 1; ++i)
		{
			int u = edges[i].u;
			int v = edges[i].v;
			
			ull weight = edges[i].weight;
			
			if (dsu.Union(u, v))
			{
				divisors += __builtin_ctzll(weight);
				j++;
			}
		}
		
		divisors++;
		
		cout << divisors << "\n";
	}
	
	return 0;
}