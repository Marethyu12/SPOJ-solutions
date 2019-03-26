#include <bits/stdc++.h>

using namespace std;

int mod(const string& s, int x)
{
	int rem = 0;
	
	int length = s.length();
	
	for (int i = 0; i < length; ++i)
	{
		rem = rem * 10 + (s[i] - '0');
		rem %= x;
	}
	
	return rem;
}

string bfs(int n)
{
	unordered_map<int, int> marked;
	queue<string> q;
	
	q.push("1");
	
	while (!q.empty())
	{
		string num = q.front();
		q.pop();
		
		int rem = mod(num, n);
		
		if (rem == 0)
			return num;
		
		if (marked.find(rem) == marked.end())
		{
			marked[rem] = 1;
			q.push(num + "0");
			q.push(num + "1");
		}
	}
	
	return "";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int K;
	int n;
	
	cin >> K;
	
	while (K--)
	{
		cin >> n;
		
		cout << bfs(n) << "\n";
	}
	
	return 0;
}