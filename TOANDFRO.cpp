#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cols;
	string s;
	
	while (true)
	{
		cin >> cols;
		cin.ignore(1, '\n');
		
		if (cols == 0)
			break;
		
		getline(cin, s);
		
		int rows = s.length() / cols;
		
		char mat[rows][cols];
		
		int i = 0;
		int j = 0;
		bool right = true;
		
		int length = rows * cols;
		
		for (int k = 0; k < length; ++k)
		{
			mat[i][j] = s[k];
			
			if (right)
			{
				if (++j == cols)
				{
					++i;
					--j;
					right = false;
				}
			}
			else
			{
				if (--j < 0)
				{
					++i;
					right = true;
					++j;
				}
			}
		}
		
		string message = "";
		
		for (int j = 0; j < cols; ++j)
			for (int i = 0; i < rows; ++i)
				message += mat[i][j];
		
		cout << message << "\n";
	}
	
	return 0;
}