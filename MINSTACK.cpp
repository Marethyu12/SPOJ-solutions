#include <bits/stdc++.h>

using namespace std;

struct Data
{
	int val;
	int minVal;
	
	Data(int val, int minVal) : val(val), minVal(minVal) {}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	string cmd;
	
	int val;
	
	cin >> n;
	cin.ignore(1, '\n');
	
	stack<Data> s;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> cmd;
		
		if (cmd == "PUSH")
		{
			cin >> val;
			
			s.push(Data(val, s.empty() ? val : min(val, s.top().minVal)));
		}
		else if (cmd == "POP")
		{
			if (s.empty())
				cout << "EMPTY\n\n";
			else
				s.pop();
		}
		else
		{
			if (s.empty())
				cout << "EMPTY\n\n";
			else
				cout << s.top().minVal << "\n\n";
		}
	}
	
	return 0;
}