#include <bits/stdc++.h>

#define MAXN 500

using namespace std;

struct cell
{
	int row;
	int col;
	
	cell(int row, int col) : row(row), col(col) {}
};

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dist[MAXN][MAXN];

int rows;
int cols;

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < rows) && (col >= 0 && col < cols);
}

int bfs()
{
	queue<cell> q;
	
	visited[0][0] = true;
	dist[0][0] = 0;
	q.push(cell(0, 0));
	
	while (!q.empty())
	{
		cell c = q.front();
		q.pop();
		
		if (c.row == rows - 1 && c.col == cols - 1)
			return dist[c.row][c.col];
		
		for (int i = 0; i < 4; ++i)
		{
			int k = grid[c.row][c.col];
			
			int row = c.row + k * dr[i];
			int col = c.col + k * dc[i];
			
			if (inBounds(row, col) && !visited[row][col])
			{
				visited[row][col] = true;
				dist[row][col] = dist[c.row][c.col] + 1;
				q.push(cell(row, col));
			}
		}
	}
	
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	
	cin >> rows >> cols;
	cin.ignore(1, '\n');
	
	for (int i = 0; i < rows; ++i)
	{
		getline(cin, s);
		
		for (int j = 0; j < cols; ++j)
			grid[i][j] = s[j] - '0';
	}
	
	cout << bfs() << "\n";
	
	return 0;
}