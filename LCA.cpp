#include <bits/stdc++.h>

using namespace std;

class LCA
{
private:
	vector<int> euler;
	vector<int> depth;
	vector<int> first;
	vector<int> st;
	vector<bool> visited;
	
	void dfs(int u, int d, vector<int> adj[])
	{
		visited[u] = true;
		depth[u] = d;
		first[u] = euler.size();
		euler.push_back(u);
		
		for (int v : adj[u])
			if (!visited[v])
			{
				dfs(v, d + 1, adj);
				euler.push_back(u);
			}
	}
	
	void build(int root, int l, int r)
	{
		if (l > r)
			return;
		
		if (l == r)
			st[root] = euler[l];
		else
		{
			int mid = l + (r - l) / 2;
			
			build(2 * root, l, mid);
			build(2 * root + 1, mid + 1, r);
			
			int left = st[2 * root];
			int right = st[2 * root + 1];
			
			st[root] = (depth[left] < depth[right]) ? left : right;
		}
	}
	
	int query(int root, int l, int r, int i, int j)
	{
		if (l > r || j < l || r < i)
			return -1;
		
		if (i <= l && r <= j)
			return st[root];
		
		int mid = l + (r - l) / 2;
		
		int left = query(2 * root, l, mid, i, j);
		int right = query(2 * root + 1, mid + 1, r, i, j);
		
		if (left == -1)
			return right;
		
		if (right == -1)
			return left;
		
		return (depth[left] < depth[right]) ? left : right;
	}
public:
	LCA(vector<int> adj[], int V, int root)
	{
		euler.reserve(2 * V);
		depth.resize(V);
		first.resize(V);
		visited.assign(V, false);
		
		dfs(root, 0, adj);
		
		int n = euler.size();
		
		st.resize(4 * n);
		build(1, 0, n - 1);
	}
	
	int lca(int u, int v)
	{
		int l = first[u];
		int r = first[v];
		
		if (l > r)
			swap(l, r);
		
		return query(1, 0, euler.size() - 1, l, r);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int V;
	int M;
	int child;
	int Q;
	int u, v;
	
	int cn = 1;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V;
		
		vector<int> adj[V];
		
		for (int i = 0; i < V; ++i)
		{
			cin >> M;
			
			for (int j = 0; j < M; ++j)
			{
				cin >> child;
				
				--child;
				
				adj[i].push_back(child);
				adj[child].push_back(i);/* REMEMBER THAT A TREE IS AN UNDIRECTED CONNECTED ACYCLIC GRAPH, IDIOT!! */
			}
		}
		
		LCA lca(adj, V, 0);
		
		cout << "Case " << cn++ << ":\n";
		
		cin >> Q;
		
		for (int qi = 0; qi < Q; ++qi)
		{
			cin >> u >> v;
			
			--u;
			--v;
			
			cout << lca.lca(u, v) + 1 << "\n";
		}
	}
	
	return 0;
}