#include <bits/stdc++.h>

using namespace std;

class DSU
{
private:
    vector<int> parent;
	vector<int> rank;
	vector<int> money;
	
	int sets;
public:
	DSU(int sets)
	{
		this->sets = sets;
		
		parent.resize(sets);
		rank.resize(sets);
		money.resize(sets);
		
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
		{
			parent[y] = x;
			money[x] += money[y];
		}
		else if (rank[x] < rank[y])
		{
			parent[x] = y;
			money[y] += money[x];
		}
		else
		{
			parent[x] = y;
			money[y] += money[x];
			++rank[y];
		}
		
		--sets;
		
		return true;
	}
	
	int countSets()
	{
		return sets;
	}
	
	void setMoney(int x, int amt)
	{
		money[Find(x)] = amt;
	}
	
	int getMoney(int x)
	{
		return money[Find(x)];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n, m;
	int amt;
	int x, y;
	
	int cn = 1;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> m;
		
		DSU dsu(n);
		
		for (int i = 0; i < n; ++i)
		{
			cin >> amt;
			
			dsu.setMoney(i, amt);
		}
		
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y;
			
			--x;
			--y;
			
			dsu.Union(x, y);
		}
		
		int sets = dsu.countSets();
		
		unordered_set<int> us;
		multiset<int> s;
		
		for (int i = 0; i < n && us.size() < sets; ++i)
		{
			int root = dsu.Find(i);
			
			if (us.find(root) == us.end())
			{
				us.insert(root);
				s.insert(dsu.getMoney(i));
			}
		}
		
		cout << "Case " << cn++ << ": " << sets << "\n";
		
		int i = 0;
		
		for (auto iter = s.begin(), stop = s.end(); iter != stop; ++iter, ++i)
			cout << *iter << " \n"[i == sets - 1];
	}
	
	return 0;
}