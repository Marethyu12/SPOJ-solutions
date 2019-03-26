#include <bits/stdc++.h>

#define MAXN 51

using namespace std;

typedef pair<int, int> coord;

const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int H;
int W;

int ans;

inline bool inBounds(int row, int col)
{
	return row >= 0 && row < H && col >= 0 && col < W;
}

void dfs(char grid[][MAXN], bool map[][MAXN], int row, int col, int length)
{
	ans = max(ans, length);
	
	map[row][col] = true;
	
	for (int i = 0; i < 8; ++i)
	{
		int r = row + dr[i];
		int c = col + dc[i];
		
		if (inBounds(r, c) && !map[r][c] && grid[r][c] == grid[row][col] + 1)
			dfs(grid, map, r, c, length + 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	long _start = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string row;
	char grid[MAXN][MAXN];
	
	for (int case_num = 1; true; ++case_num)
	{
		cin >> H >> W;
		cin.ignore(1, '\n');
		
		if (H == 0 && W == 0)
			break;
		
		vector<coord> v;
		bool map[MAXN][MAXN] = {{false}};
		
		for (int i = 0; i < H; ++i)
		{
			getline(cin, row);
			
			for (int j = 0; j < W; ++j)
			{
				if (row[j] == 'A')
					v.push_back(make_pair(i, j));
				
				grid[i][j] = row[j];
			}
		}
		
		ans = 0;
		
		for (const coord& c : v)
			dfs(grid, map, c.first, c.second, 1);
		
		cout << "Case " << case_num << ": " << ans << "\n";
	}
	
#ifndef ONLINE_JUDGE
    cout << "\nprocess terminated in " << (clock() - _start) << "ms\n";
#endif
	return 0;
}