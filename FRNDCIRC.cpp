#include <bits/stdc++.h>

using namespace std;

class DSU
{
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;
public:
	DSU(int sets)
	{
		parent.resize(sets);
		rank.resize(sets);
		size.resize(sets);
		
		for (int i = 0; i < sets; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
			size[i] = 1;
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
		
		if (parent[u] == parent[v])
			return false;
		
		if (rank[u] > rank[v])
		{
			parent[v] = u;
			size[u] += size[v];
		}
		else if (rank[u] < rank[v])
		{
			parent[u] = v;
			size[v] += size[u];
		}
		else
		{
			parent[u] = v;
			size[v] += size[u];
			++rank[v];
		}
		
		return true;
	}
	
	int Size(int v)
	{
		return size[Find(v)];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	string connected;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		cin.ignore(1, '\n');
		
		map<string, int> m;//we want O(logn) search per query not O(n) with hashtable
		DSU dsu(2 * n);//there's maximum of 2 * n people for n edges
		
		int mark = -1;
		
		for (int i = 0; i < n; ++i)
		{
			getline(cin, connected);
			
			int pos = connected.find(" ");
			
			string a = connected.substr(0, pos);
			string b = connected.substr(pos + 1);
			
			if (m.find(a) == m.end())
				m[a] = ++mark;
			
			if (m.find(b) == m.end())
				m[b] = ++mark;
			
			int u = m[a];
			int v = m[b];
			
			dsu.Union(u, v);
			
			cout << dsu.Size(u) << "\n";
		}
	}
	
	return 0;
}