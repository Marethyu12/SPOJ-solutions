#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int q;
	int type;
	ll val;
	int l, r;
	
	cin >> n;
	
	vector<ll> v(n);
	
	for (int i = n - 1; i >= 0; --i)
		cin >> v[i];
	
	vector<ll> sum(n);
	
	sum[0] = v[0];
	
	for (int i = 1; i < n; ++i)
		sum[i] = sum[i - 1] + v[i];
	
	cin >> q;
	
	for (int qi = 0; qi < q; ++qi)
	{
		cin >> type;
		
		if (type == 1)
		{
			cin >> l >> r;
			
			--l;
			--r;
			
			//remember that the prefix sum array is inverted
			l = (int(sum.size()) - l) - 1;
			r = (int(sum.size()) - r) - 1;
			
			swap(l, r);
			
			if (l == 0)
				cout << sum[r] << "\n";
			else
				cout << sum[r] - sum[l - 1] << "\n";
		}
		else
		{
			cin >> val;
			
			sum.push_back(sum.back() + val);
		}
	}
	
	return 0;
}