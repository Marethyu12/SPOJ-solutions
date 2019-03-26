#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

int multiply(int *product, int product_size, int x)
{
	int carry = 0;
	
	for (int i = 0; i < product_size; ++i)
	{
		int prod = product[i] * x + carry;
		
		product[i] = prod % 10;
		carry = prod / 10;
	}
	
	while (carry)
	{
		product[product_size] = carry % 10;
		carry /= 10;
		product_size++;
	}
	
	return product_size;
}

void factorial(int n)
{
	int product[MAX];
	int size = 1;
	
	product[0] = 1;
	
	for (int x = 2; x <= n; ++x)
		size = multiply(product, size, x);
	
	for (int i = size; i --> 0;)
		cout << product[i];
	
	cout << "\n";
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
	
	int T;
	int N;
	
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		
		factorial(N);
	}
	
#ifndef ONLINE_JUDGE
    cout << "\nprocess terminated in " << (clock() - _start) << "ms\n";
#endif
	return 0;
}