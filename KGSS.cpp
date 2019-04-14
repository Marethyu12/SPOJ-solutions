#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

/*
 * Custom segtree node
 */
struct Node
{
	int max1;//maximum #1
	int max2;//maximum #2
	
	Node() {}
	
	Node(int max1, int max2) : max1(max1), max2(max2) {}
	
	Node operator+(const Node& other)
	{
		Node node;
		
		vector<int> v;
		
		v.push_back(max1);
		v.push_back(max2);
		v.push_back(other.max1);
		v.push_back(other.max2);
		
		sort(v.begin(), v.end());
		
		node.max1 = v[int(v.size()) - 1];
		node.max2 = v[int(v.size()) - 2];
		
		return node;
	}
};

Node st[4 * MAXN];

void build(int root, int l, int r, const vector<int>& v)
{
	if (l > r)
		return;
	
	if (l == r)
		st[root] = Node(v[l], -1);
	else
	{
		int mid = l + (r - l) / 2;
		
		build(2 * root, l, mid, v);
		build(2 * root + 1, mid + 1, r, v);
		
		st[root] = st[2 * root] + st[2 * root + 1];
	}
}

void update(int root, int l, int r, int index, int value)
{
	if (l > r)
		return;
	
	if (l == r)
		st[root].max1 = value;
	else
	{
		int mid = l + (r - l) / 2;
		
		if (index <= mid)
			update(2 * root, l, mid, index, value);
		else
			update(2 * root + 1, mid + 1, r, index, value);
		
		st[root] = st[2 * root] + st[2 * root + 1];
	}
}

Node query(int root, int l, int r, int i, int j)
{
	if (l > r || j < l || r < i)
		return Node(-1, -1);
	
	if (i <= l && r <= j)
		return st[root];
	
	int mid = l + (r - l) / 2;
	
	Node left = query(2 * root, l, mid, i, j);
	Node right = query(2 * root + 1, mid + 1, r, i, j);
	
	return left + right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int q;
	
	char c;
	
	int ind, val;
	int i, j;
	
	cin >> n;
	
	vector<int> v(n);
	
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	build(1, 0, n - 1, v);
	
	cin >> q;
	
	for (int qi = 0; qi < q; ++qi)
	{
		cin >> c;
		
		if (c == 'U')
		{
			cin >> ind >> val;
			
			--ind;
			
			update(1, 0, n - 1, ind, val);
		}
		else
		{
			cin >> i >> j;
			
			--i;
			--j;
			
			Node node = query(1, 0, n - 1, i, j);
			
			cout << node.max1 + node.max2 << "\n";
		}
	}
	
	return 0;
}