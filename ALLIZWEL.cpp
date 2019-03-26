#include <bits/stdc++.h>

#define MAXN 100

using namespace std;

const string phrase = "ALLIZZWELL";

const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

int R;
int C;

bool found;

inline bool inBounds(int row, int col)
{
	return (row >= 0 && row < R) && (col >= 0 && col < C);
}

void dfs(int row, int col, int index)
{
	if (index == phrase.length() - 1)
	{
		found = true;
		return;
	}
	
	visited[row][col] = true;
	
	for (int i = 0; i < 8; ++i)
	{
		int new_row = row + dr[i];
		int new_col = col + dc[i];
		
		if (!found && inBounds(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == phrase[index + 1])
			dfs(new_row, new_col, index + 1);
	}
	
	visited[row][col] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	fill_n(*visited, MAXN * MAXN, false);
	
	int T;
	
	cin >> T;
	
	while (T--)
	{
		cin >> R >> C;
		
		vector<pair<int, int>> v;
		
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
			{
				cin >> grid[i][j];
				
				if (grid[i][j] == 'A')
					v.push_back(make_pair(i, j));
			}
		
		found = false;
		
		for (const pair<int, int>& pii : v)
		{
			dfs(pii.first, pii.second, 0);
			
			if (found)
				break;
		}
		
		cout << (found ? "YES\n" : "NO\n");
	}
	
	return 0;
}