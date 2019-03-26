#include <bits/stdc++.h>

#define MAXN 250

using namespace std;

char field[MAXN][MAXN];
bool visited[MAXN][MAXN];

int rows;
int cols;

void dfs(int row, int col, int& sheeps, int& wolves)
{
	if (row < 0 || row > rows - 1 || col < 0 || col > cols - 1 || visited[row][col] || field[row][col] == '#')
		return;
	
	sheeps += (field[row][col] == 'k');
	wolves += (field[row][col] == 'v');
	
	visited[row][col] = true;
	
	dfs(row + 1, col, sheeps, wolves);
	dfs(row - 1, col, sheeps, wolves);
	dfs(row, col + 1, sheeps, wolves);
	dfs(row, col - 1, sheeps, wolves);
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
			field[i][j] = s[j];
	}
	
	int sheeps = 0;
	int wolves = 0;
	
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			if (!visited[i][j] && field[i][j] != '#')
			{
				int s = 0;
				int w = 0;
				
				dfs(i, j, s, w);
				
				if (s <= w)//if wolves outnumber sheeps in a component, they will be eaten even there's same number of sheeps and wolves
					s = 0;
				
				if (s > w)//if sheeps outnumber wolves in a component, sheeps will fuck them to death
					w = 0;
				
				sheeps += s;
				wolves += w;
			}
	
	cout << sheeps << " " << wolves << "\n";
	
	return 0;
}