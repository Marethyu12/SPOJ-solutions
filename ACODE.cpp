#include <bits/stdc++.h>

using namespace std;

string nums[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};

int decodings(const string& code, int pos)
{
	if (pos == code.length())
		return 1;
	
	int q = 0;
	
	for (int i = 0; i < 26; ++i)
	{
		string num = nums[i];
		
		int length = int(num.length());
		
		if (pos + length > code.length())
			break;
		
		int j;
		
		for (j = 0; j < length; ++j)
			if (num[j] != code[pos + j])
				break;
		
		if (j == length)
			q += decodings(code, pos + length);
	}
	
	return q;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string code;
	
	while (true)
	{
		getline(cin, code);
		
		if (code == "0")
			break;
		
		int n = int(code.length());
		
		int dp[n + 1];
		
		dp[n] = 1;
		
		for (int i = n - 1; i >= 0; --i)
		{
			int q = 0;
			
			for (int j = 0; j < 26; ++j)
			{
				string num = nums[j];
				
				int length = int(num.length());
				
				if (i + length > n)
					break;
				
				int k;
				
				for (k = 0; k < length; ++k)
					if (num[k] != code[i + k])
						break;
				
				if (k == length)
					q += dp[i + length];
			}
			
			dp[i] = q;
		}
		
		cout << dp[0] << "\n";
	}
	
	return 0;
}