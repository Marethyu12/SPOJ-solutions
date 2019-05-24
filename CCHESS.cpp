#include <bits/stdc++.h>

#define n 8
#define INF 0x7FFFFFFF

using namespace std;

struct cell
{
	int row;
	int col;
	
	cell(int row, int col) : row(row), col(col) {}
	
	bool operator<(const cell& other) const
	{
		return true;
	}
};

const int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

inline int cost(int a, int b, int c, int d)
{
	return a * c + b * d;
}

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < n) && (col >= 0 && col < n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, c, d;
	
	while (cin >> a >> b >> c >> d)
	{
		priority_queue<pair<int, cell>, vector<pair<int, cell>>, greater<pair<int, cell>>> pq;
		
		int dist[n][n];
		
		for (int i = 0; i < n; ++i)
			fill(dist[i], dist[i] + n, INF);
		
		pq.push(make_pair(0, cell(a, b)));
		dist[a][b] = 0;
		
		while (!pq.empty())
		{
			cell c = pq.top().second;
			pq.pop();
			
			for (int i = 0; i < 8; ++i)
			{
				int row = c.row + dr[i];
				int col = c.col + dc[i];
				int pay = cost(c.row, c.col, row, col);
				
				if (inBounds(row, col) && dist[row][col] > dist[c.row][c.col] + pay)
				{
					dist[row][col] = dist[c.row][c.col] + pay;
					pq.push(make_pair(dist[row][col], cell(row, col)));
				}
			}
		}
		
		cout << dist[c][d] << "\n";
	}
	
	return 0;
}