#include <bits/stdc++.h>

using namespace std;

void update(int x, int y, int by, vector<vector<int>>& BIT)
{
	int n = int(BIT.size());
	
	for (int i = x; i < n; i |= (i + 1))
		for (int j = y; j < n; j |= (j + 1))
			BIT[i][j] += by;
}

int query(int x, int y, const vector<vector<int>>& BIT)
{
	int sum = 0;
	
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			sum += BIT[i][j];
	
	return sum;
}

int query(int x1, int y1, int x2, int y2, const vector<vector<int>>& BIT)
{
	return query(x2, y2, BIT) - query(x1 - 1, y2, BIT) - query(x2, y1 - 1, BIT) + query(x1 - 1, y1 - 1, BIT);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	string s;
	
	int x, y, val;
	int x1, y1, x2, y2;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		cin.ignore(1, '\n');
		
		vector<vector<int>> BIT(n, vector<int>(n, 0));
		
		bool stop = false;
		
		while (!stop)
		{
			cin >> s;
			
			switch (s[1])
			{
				case 'E':
					cin >> x >> y >> val;
					
					update(x, y, val - query(x, y, x, y, BIT), BIT);
					
					break;
				case 'U':
					cin >> x1 >> y1 >> x2 >> y2;
					
					cout << query(x1, y1, x2, y2, BIT) << "\n";
					
					break;
				case 'N':
					stop = true;
					break;
			}
		}
	}
	
	return 0;
}