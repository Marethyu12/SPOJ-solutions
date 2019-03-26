#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const char BLOCKED = 'X';

struct cell
{
	int row;
	int col;
	int dir;
	int dist;
	
	cell() {}
	
	cell(int row, int col, int dir, int dist) : row(row), col(col), dir(dir), dist(dist) {}
};

char board[MAXN][MAXN];

int R;
int C;

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < R) && (col >= 0 && col < C);
}

int bfs(const cell& source)
{
	int visited[R][C]; /* don't use bool visited array, it won't work */
	queue<cell> q;
	
	fill_n(*visited, R * C, 0);
	
	visited[source.row][source.col] = 255;
	q.push(source);
	
	while (!q.empty())
	{
		cell c = q.front();
		q.pop();
		
		if (board[c.row][c.col] == 'F')
			return c.dist;
		
		for (int i = 0; i < 8; ++i)
		{
			int row = c.row + dr[i];
			int col = c.col + dc[i];
			
			while (inBounds(row, col) && board[row][col] != BLOCKED &&
			       !(visited[row][col] & (1 << i))) /* that direction's not visited (ith bit not set) */
			{
				if (!visited[row][col]) /* only the best ones goes to the queue */
					q.push(cell(row, col, i, c.dist + 1));
				
				visited[row][col] |= (1 << i); /* make that direction visited (set ith bit) */
				
				row += dr[i];
				col += dc[i];
			}
		}
	}
	
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	string row;
	
	cin >> T;
	
	while (T--)
	{
		cin >> R >> C;
		cin.ignore(1, '\n');
		
		cell source;
		
		for (int i = 0; i < R; ++i)
		{
			getline(cin, row);
			
			for (int j = 0; j < C; ++j)
			{
				board[i][j] = row[j];
				
				if (board[i][j] == 'S')
				{
					source.row = i;
					source.col = j;
					source.dir = -1;
					source.dist = 0;
				}
			}
		}
		
		cout << bfs(source) << "\n";
	}
	
	return 0;
}