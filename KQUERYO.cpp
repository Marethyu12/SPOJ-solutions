/*
 * Learned: vectors can be used as segment tree nodes!
 */
#include <bits/stdc++.h>

#define MAXN 30000

using namespace std;

vector<int> st[4 * MAXN];

void merge(vector<int>& v, const vector<int>& left, const vector<int>& right)
{
	v.resize(int(left.size()) + int(right.size()));
	
	int size1 = int(left.size());
	int size2 = int(right.size());
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i < size1 && j < size2)
		if (left[i] <= right[j])
			v[k++] = left[i++];
		else
			v[k++] = right[j++];
	
	while (i < size1)
		v[k++] = left[i++];
	
	while (j < size2)
		v[k++] = right[j++];
}

void build(int root, int l, int r, int nums[])
{
	if (l > r)
		return;
	
	if (l == r)
		st[root].push_back(nums[l]);
	else
	{
		int mid = l + (r - l) / 2;
		
		build(2 * root, l, mid, nums);
		build(2 * root + 1, mid + 1, r, nums);
		
		merge(st[root], st[2 * root], st[2 * root + 1]);
	}
}

int query(int root, int l, int r, int i, int j, int k)
{
	if (l > r || j < l || r < i)
		return -1;
	
	if (i <= l && r <= j)
		return st[root].size() - distance(st[root].begin(), upper_bound(st[root].begin(), st[root].end(), k));
	
	int mid = l + (r - l) / 2;
	
	int left = query(2 * root, l, mid, i, j, k);
	int right = query(2 * root + 1, mid + 1, r, i, j, k);
	
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
	
	int n;
	int q;
	int i, j, k;
	
	int last = 0;
	
	cin >> n;
	
	int nums[n];
	
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	
	build(1, 0, n - 1, nums);
	
	cin >> q;
	
	for (int qi = 0; qi < q; ++qi)
	{
		cin >> i >> j >> k;
		
		i ^= last;
		j ^= last;
		k ^= last;
		
		--i;
		--j;
		
		if (i < 0)
			i = 0;
		
		if (j > n - 1)
			j = n - 1;
		
		if (i <= j)
			last = query(1, 0, n - 1, i, j, k);
		else
			last = 0;//when i > j
		
		cout << last << "\n";
	}
	
	return 0;
}