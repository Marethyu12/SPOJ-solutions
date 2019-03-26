#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

struct cell
{
	int row;
	int col;
	
	cell(int row, int col) : row(row), col(col) {}
};

const int dr[] = {-1, 0, 0, 1};
const int dc[] = {0, -1, 1, 0};

const char direction[] = {'N', 'W', 'E', 'S'};// directions based on index from dr and dc
const char opposite[] = {'S', 'E', 'W', 'N'};// directions opposite based on index from dr and dc

char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

int rows;
int cols;

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < rows) && (col >= 0 && col < cols);
}

void bfs(const cell& source)
{
	queue<cell> q;
	
	q.push(source);
	
	while (!q.empty())
	{
		cell c = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int row = c.row + dr[i];
			int col = c.col + dc[i];
			
			if (inBounds(row, col) && !visited[row][col] &&
				(grid[c.row][c.col] == direction[i] || grid[row][col] == opposite[i]))// if indexed direction matches the current cell's direction on grid or next cell's direction on the grid is opposite of indexed direction
			{
				visited[row][col] = true;
				q.push(cell(row, col));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	
	cin >> rows >> cols;
	cin.ignore(1, '\n');
	
	for (int i = 0; i < rows; ++i)
	{
		getline(cin, s);
		
		for (int j = 0; j < cols; ++j)
			grid[i][j] = s[j];
	}
	
	int connected_components = 0;
	
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			if (!visited[i][j])
			{
				cell c(i, j);
				
				bfs(c);
				
				++connected_components;
			}
	
	cout << connected_components << "\n";
	
	return 0;
}