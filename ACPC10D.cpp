#include <bits/stdc++.h>

#define MAXN 100000
#define INF 0x3F3F3F3F

using namespace std;

const int dr[] = {1, 1, 1, 0};
const int dc[] = {-1, 0, 1, 1};

int g[MAXN][3];
int memo[MAXN][3];

int n;

int cost(int row, int col)
{
	if (memo[row][col] != -1)
		return memo[row][col];
	
	if (row == n - 1 && col == 1)
		return g[row][col];
	
	int q = INF;
	
	for (int i = 0; i < 4; ++i)
	{
		int r = row + dr[i];
		int c = col + dc[i];
		
		if (r >= 0 && r < n && c >= 0 && c < 3)
			q = min(q, g[row][col] + cost(r, c));
	}
	
	return memo[row][col] = q;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int cn = 1;
	
	while (true)
	{
		cin >> n;
		
		if (n == 0)
			break;
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> g[i][j];
		
		memset(memo, -1, sizeof(memo));
		
		cout << cn++ << ". " << cost(0, 1) << "\n";
	}
	
	return 0;
}