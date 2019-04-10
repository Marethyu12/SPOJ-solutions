#include <bits/stdc++.h>

#define MAXN 100001
#define lowbit(n) (n) & -(n)

using namespace std;

typedef long long int ll;

ll BIT[MAXN];

void update(int index, int by)
{
	while (index < MAXN)
	{
		BIT[index] += by;
		index += lowbit(index);
	}
}

ll query(int index)
{
	ll sum = 0;
	
	while (index > 0)
	{
		sum += BIT[index];
		index -= lowbit(index);
	}
	
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		memset(BIT, 0, sizeof(BIT));
		
		int nums[n];
		int order[n];
		
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
			
			order[i] = nums[i];
		}
		
		sort(order, order + n);
		
		unordered_map<int, int> m;
		
		for (int i = 0; i < n; ++i)
			m[order[i]] = i + 1;//coordinate compression
		
		ll total = 0;
		
		for (int i = 0; i < n; ++i)
		{
			total += query(m[nums[i]] - 1);
			
			update(m[nums[i]], nums[i]);
		}
		
		cout << total << "\n";
	}
	
	return 0;
}