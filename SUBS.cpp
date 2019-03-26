#include <bits/stdc++.h>

using namespace std;

string str_pow(const string& X, int M)
{
	string raised = "";
	
	int length = X.length();
	
	for (int i = 0; i < length; ++i)
		for (int j = 0; j < M; ++j)
			raised += X[i];
	
	return raised;
}

bool subsequence(const string& a, const string& b)
{
	int index = 0;
	
	int length = a.length();
	
	for (int i = 0; i < length; ++i)
		if (a[i] == b[index])
			index++;
	
	return index == b.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	
	string X;
	string Y;
	
	cin >> T;
	cin.ignore(1, '\n');
	
	while (T--)
	{
		getline(cin, X);
		getline(cin, Y);
		
		int low = 0;
		int high = Y.length() / X.length();
		
		while (low <= high)
		{
			int mid = (low + high) >> 1;
			
			if (subsequence(Y, str_pow(X, mid)))
				low = mid + 1;
			else
				high = mid - 1;
		}
		
		cout << high << "\n";
	}
	
	return 0;
}