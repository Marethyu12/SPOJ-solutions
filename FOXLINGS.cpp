#include <bits/stdc++.h>

using namespace std;

class DSU
{
private:
	map<int, int> parent;
	map<int, int> rank;
	
	int sets;
public:
	DSU(int sets)
	{
		this->sets = sets;
	}
	
	int Find(int x)
	{
		if (x != parent[x])
			parent[x] = Find(parent[x]);
		
		return parent[x];
	}
	
	bool Union(int x, int y)
	{
		if (parent.find(x) == parent.end())
			makeSet(x);
		
		if (parent.find(y) == parent.end())
			makeSet(y);
		
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
			++rank[y];
		}
		
		--sets;
		
		return true;
	}
	
	void makeSet(int x)
	{
		parent[x] = x;
		rank[x] = 0;
	}
	
	int countSets()
	{
		return sets;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	int x, y;
	
	cin >> n >> m;
	
	DSU dsu(n);
	
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		
		--x;
		--y;
		
		dsu.Union(x, y);
	}
	
	cout << dsu.countSets() << "\n";
	
	return 0;
}