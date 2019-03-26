#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> tree;

int *dp;
int *new_dp;

void addEdge(int u, int v)
{
	if (tree.find(u) == tree.end())
	{
		vector<int> vec(1, v);
		tree[u] = vec;
	}
	else
		tree[u].push_back(v);
	
	if (tree.find(v) == tree.end())
	{
		vector<int> vec(1, u);
		tree[v] = vec;
	}
	else
		tree[v].push_back(u);
}

void dfs1(int vertex, int parent)
{
	dp[vertex] = dp[parent] + 1;
	
	for (int neighbour : tree.at(vertex))
		if (neighbour != parent)
			dfs1(neighbour, vertex);
}

void dfs2(int vertex, int parent)
{
	new_dp[vertex] = new_dp[parent] + 1;
	
	for (int neighbour : tree.at(vertex))
		if (neighbour != parent)
			dfs2(neighbour, vertex);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int u, v;
	
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> u >> v;
		
		addEdge(u, v);
	}
	
	dp = new int[N + 1];
	
	dp[0] = -1;
	
	dfs1(1, 0);
	
	int vertex;
	int best = 0;
	
	for (int i = 1; i <= N; ++i)
		if (best < dp[i])
		{
			vertex = i;
			best = dp[i];
		}
	
	new_dp = new int[N + 1];
	
	new_dp[0] = -1;
	
	dfs2(vertex, 0);
	
	int diameter = 0;
	
	for (int i = 0; i <= N; ++i)
		diameter = max(diameter, new_dp[i]);
	
	cout << diameter << "\n";
	
	return 0;
}