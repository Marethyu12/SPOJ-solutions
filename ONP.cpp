#include <bits/stdc++.h>

using namespace std;

int priority(char op)
{
	switch (op)
	{
		case '^':
			return 5;
		case '/':
			return 4;
		case '*':
			return 3;
		case '-':
			return 2;
		case '+':
			return 1;
	}
}

string toRPN(const string& expr)
{
	stack<char> s;
	
	string rpn;
	
	for (int i = 0, length = int(expr.length()); i < length; ++i)
	{
		char c = expr[i];
		
		if (isalpha(c))
			rpn += c;
		else if (c == '(')
			s.push(c);
		else if (c == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				rpn += s.top();
				s.pop();
			}
			
			s.pop();//remove '('
		}
		else//if it's an operator
		{
			while (!s.empty() && s.top() != '(' && priority(s.top()) > priority(c))
			{
				rpn += s.top();
				s.pop();
			}
			
			s.push(c);
		}
	}
	
	while (!s.empty())
	{
		rpn += s.top();
		s.pop();
	}
	
	return rpn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	
	string s;
	
	cin >> T;
	cin.ignore(1, '\n');
	
	while (T--)
	{
		getline(cin, s);
		
		cout << toRPN(s) << "\n";
	}
	
	return 0;
}