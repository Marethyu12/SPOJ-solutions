#include <bits/stdc++.h>

#define rows 1000
#define cols 1000

using namespace std;

struct cell
{
	int row;
	int col;
	
	cell(int row, int col) : row(row), col(col) {}
};

const int dr[] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int dc[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool visited[rows][cols];
int dist[rows][cols];

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < rows) && (col >= 0 && col < cols);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	/*
	 * There are multiple queries to find distance between cell(a, b) to cell(0, 0).
	 * Since there are same cell cell(0, 0) each time, it's best to precompute distances from cell(0, 0) to all cells
	 */
	queue<cell> q;
	
	visited[0][0] = true;
	dist[0][0] = 0;
	q.push(cell(0, 0));
	
	while (!q.empty())
	{
		cell c = q.front();
		q.pop();
		
		for (int i = 0; i < 8; ++i)
		{
			int row = c.row + dr[i];
			int col = c.col + dc[i];
			
			if (inBounds(row, col) && !visited[row][col])
			{
				visited[row][col] = true;
				dist[row][col] = dist[c.row][c.col] + 1;
				q.push(cell(row, col));
			}
		}
	}
	
	int T;
	int row, col;
	
	cin >> T;
	
	while (T--)
	{
		cin >> row >> col;
		
		--row;
		--col;
		
		cout << dist[row][col] << "\n";
	}
	
	return 0;
}