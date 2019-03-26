#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int inc[4][2] = {{1, 1}, {1, -1}, {1, 1}, {-1, 1}};
	
	int T;
	int dx, dy;
	
	cin >> T;
	
	while (T--)
	{
		cin >> dx >> dy;
		
		if (dx == 0 && dy == 0)
		{
			cout << "0\n";
			continue;
		}
		
		bool reached = false;
		
		int x = 0;
		int y = 0;
		int n = 1;
		
		for (int i = 0; x < dx || y < dy; i = ++i % 4, ++n)
		{
			x += inc[i][0];
			y += inc[i][1];
			
			if (x == dx && y == dy)
			{
				reached = true;
				break;
			}
		}
		
		if (reached)
			cout << n << "\n";
		else
			cout << "No Number\n";
	}
	
	return 0;
}