/*
SPOJ Problem: LABYR1

This question asks to find a diameter of a tree

Algorithm: Double Depth First Search

Pick any starting coordinate (call it start, perform dfs on start
During this dfs, the endpoint of longest path will be called end.
Then reset the visited array and call dfs on end, the longest path from this dfs will be an answer
*/

#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

int R;
int C;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dist[MAXN][MAXN];
int best;
int start_row, start_col;
int end_row, end_col;

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < R) && (col >= 0 && col < C);
}

void dfs(int row, int col, int p_row, int p_col)
{
	if (!inBounds(row, col) || visited[row][col] || maze[row][col] == '#')
		return;
	
	visited[row][col] = true;
	dist[row][col] = (p_row > -1 && p_col > -1) ? dist[p_row][p_col] + 1 : 0;
	
	dfs(row, col + 1, row, col);
	dfs(row, col - 1, row, col);
	dfs(row + 1, col, row, col);
	dfs(row - 1, col, row, col);
	
	visited[row][col] = false;
	
	if (best < dist[row][col])
	{
		best = dist[row][col];
		end_row = row;
		end_col = col;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	
	cin >> T;
	
	while (T--)
	{
		cin >> C >> R;
		
		start_row = start_col = -1;
		
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
			{
				cin >> maze[i][j];
				
				if (start_row == -1 && start_col == -1 && maze[i][j] == '.')
				{
					start_row = i;
					start_col = j;
				}
			}
		
		fill_n(*visited, R * C, false);
		best = 0;
		
		dfs(start_row, start_col, -1, -1);
		dfs(end_row, end_col, -1, -1);
		
		cout << "Maximum rope length is " << best << ".\n";
	}
	
	return 0;
}