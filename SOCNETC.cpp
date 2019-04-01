#include <bits/stdc++.h>

using namespace std;

class DSU
{
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;
	
	int limit;
public:
	DSU(int sets, int limit)
	{
		this->limit = limit;
		
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
		
		if (parent[x] == parent[y] || size[x] + size[y] > limit)
			return false;
		
		if (rank[x] > rank[y])
		{
			parent[y] = x;
			size[x] += size[y];
		}
		else if (rank[x] < rank[y])
		{
			parent[x] = y;
			size[y] += size[x];
		}
		else
		{
			parent[x] = y;
			size[y] += size[x];
			++rank[y];
		}
		
		return true;
	}
	
	int Size(int x)
	{
		return size[Find(x)];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	int q;
	
	char op;
	
	int x, y;
	
	cin >> n >> m;
	
	DSU dsu(n, m);
	
	cin >> q;
	
	for (int qi = 0; qi < q; ++qi)
	{
		cin >> op;
		
		if (op == 'A')
		{
			cin >> x >> y;
			
			--x;
			--y;
			
			dsu.Union(x, y);
		}
		else if (op == 'E')
		{
			cin >> x >> y;
			
			--x;
			--y;
			
			cout << (dsu.Find(x) == dsu.Find(y) ? "Yes\n" : "No\n");
		}
		else
		{
			cin >> x;
			
			--x;
			
			cout << dsu.Size(x) << "\n";
		}
	}
	
	return 0;
}