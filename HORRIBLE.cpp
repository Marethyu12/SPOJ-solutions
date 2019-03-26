#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

typedef long long ll;

ll st[4 * MAXN];
ll lazy[4 * MAXN];

void update(int root, int l, int r, int i, int j, ll value)
{
	if (lazy[root] != 0)
	{
		st[root] += (r - l + 1) * lazy[root];
		
		if (l != r)
		{
			lazy[2 * root] += lazy[root];
			lazy[2 * root + 1] += lazy[root];
		}
		
		lazy[root] = 0;
	}
	
	if (l > r || j < l || r < i) /* out of range */
		return;
	
	if (i <= l && r <= j) /* fully in range */
	{
		st[root] += (r - l + 1) * value;
		
		if (l != r)
		{
			lazy[2 * root] += value;
			lazy[2 * root + 1] += value;
		}
		
		return;
	}
	
	int mid = l + (r - l) / 2;
	
	update(2 * root, l, mid, i, j, value);
	update(2 * root + 1, mid + 1, r, i, j, value);
	
	st[root] = st[2 * root] + st[2 * root + 1];
}

ll query(int root, int l, int r, int i, int j)
{
	if (l > r || j < l || r < i)
		return -1;
	
	if (lazy[root] != 0)
	{
		st[root] += (r - l + 1) * lazy[root];
		
		if (l != r)
		{
			lazy[2 * root] += lazy[root];
			lazy[2 * root + 1] += lazy[root];
		}
		
		lazy[root] = 0;
	}
	
	if (i <= l && r <= j)
		return st[root];
	
	int mid = l + (r - l) / 2;
	
	ll left = query(2 * root, l, mid, i, j);
	ll right = query(2 * root + 1, mid + 1, r, i, j);
	
	if (left == -1)
		return right;
	
	if (right == -1)
		return left;
	
	return left + right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n, q;
	int cmd, qs, qe;
	
	ll by;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> q;
		
		memset(st, 0, sizeof(st));
		memset(lazy, 0, sizeof(lazy));
		
		for (int i = 0; i < q; ++i)
		{
			cin >> cmd;
			
			if (cmd == 0)
			{
				cin >> qs >> qe >> by;
				
				update(1, 0, n - 1, qs - 1, qe - 1, by);
			}
			else
			{
				cin >> qs >> qe;
				
				cout << query(1, 0, n - 1, qs - 1, qe - 1) << "\n";
			}
		}
	}
	
	return 0;
}