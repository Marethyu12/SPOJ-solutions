#include <bits/stdc++.h>

using namespace std;

struct cow
{
	int gallons;
	int deadline;
	
	cow(int gallons, int deadline) : gallons(gallons), deadline(deadline) {}
	
	bool operator<(const cow& other)
	{
		return gallons > other.gallons;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int gallons, deadline;
	
	cin >> n;
	
	vector<cow> v;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> gallons >> deadline;
		
		v.push_back(cow(gallons, deadline));
	}
	
	bool slot[n] = {false};
	
	int max_gallons = 0;
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; ++i)
		for (int j = min(n, v[i].deadline) - 1; j >= 0; --j)
			if (!slot[j])
			{
				slot[j] = true;
				max_gallons += v[i].gallons;
				break;
			}
	
	cout << max_gallons << "\n";
	
	return 0;
}