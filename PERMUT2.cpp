#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	while (true)
	{
		cin >> n;
		
		if (n == 0)
			break;
		
		vector<int> v(n);//remember that ith element in v is a position for number i in inverse permutation
		
		for (int i = 0; i < n; --v[i++])//decrement element to fit 0 based indexing
			cin >> v[i];
		
		vector<int> tmp(n);
		
		for (int i = 0; i < n; ++i)
			tmp[v[i]] = i;
		
		if (v == tmp)//permutation and its inverse matches
			cout << "ambiguous\n";//ambiguous permutation is a permutation which cannot be distinguished from its inverse permutation
		else
			cout << "not ambiguous\n";
	}
	
	return 0;
}