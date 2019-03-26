#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coord;

int n, m;

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < n) && (col >= 0 && col < m);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int dr[] = {-1, 0, 0, 1};
	int dc[] = {0, -1, 1, 0};
	
	int BLACK = 0;
	int WHITE = 1;
	int FLAG = -1;
	
	int T;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> m;
		cin.ignore(1, '\n');
		
		string row;
		
		int dist[n][m];
		queue<coord> q;
		
		for (int i = 0; i < n; ++i)
		{
			getline(cin, row);
			
			for (int j = 0; j < m; ++j)
			{
				dist[i][j] = row[j] - '0';
				
				if (dist[i][j] == WHITE)
				{
					dist[i][j] = FLAG;
					q.push(make_pair(i, j));
				}
			}
		}
		
		while (!q.empty())//multisource bfs
		{
			coord c = q.front();
			q.pop();
			
			for (int i = 0; i < 4; ++i)
			{
				int row = c.first + dr[i];
				int col = c.second + dc[i];
				
				if (inBounds(row, col) && dist[row][col] == BLACK)
				{
					dist[row][col] = dist[c.first][c.second] + 1;
					
					if (dist[c.first][c.second] == FLAG)
						dist[row][col]++;
					
					q.push(make_pair(row, col));
				}
			}
		}
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				if (dist[i][j] == FLAG)
					cout << "0 ";
				else
					cout << dist[i][j] << " ";
			
			cout << "\n";
		}
	}
	
	return 0;
}