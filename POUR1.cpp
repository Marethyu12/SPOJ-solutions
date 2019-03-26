#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return abs(a);
	
	return gcd(b, a % b);
}

int pour(int a, int b, int c)
{
	int x = a;
	int y = 0;
	
	int steps = 1;
	
	while (x != c && y != c)
	{
		int amt = min(x, b - y);//decide how much to transfer from y to x
		
		x -= amt;
		y += amt;//transfer
		
		++steps;
		
		if (x == c || y == c)//if goal reached, stop
			break;
		
		if (x == 0)//if x is empty, then fill
		{
			x = a;
			++steps;
		}
		
		if (y == b)//if y is full then empty it
		{
			y = 0;
			++steps;
		}
	}
	
	return steps;
}

//solves problem using a diophantine equation: ax + by = c
//where x means # times to fill a (+) or empty a (-)
//where y means # times to fill b (+) or empty b (-)
//solution exists only if c is divisible by gcd(a, b)
int min_steps(int a, int b, int c)
{
	if (a > b)
		swap(a, b);//ensure that a is less than b for conditionals below
	
	if (b < c)
		return -1;//c is too big
	
	if (c % gcd(a, b) != 0)
		return -1;//no solution to the diophantine equation
	
	return min(pour(a, b, c), pour(b, a, c));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int a;
	int b;
	int c;
	
	cin >> T;
	
	while (T--)
	{
		cin >> a;
		cin >> b;
		cin >> c;
		
		cout << min_steps(a, b, c) << "\n";
	}
	
	return 0;
}