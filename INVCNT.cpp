#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll merge(int nums[], int temp[], int low, int mid, int high)
{
	ll inversions = 0;
	
	int i = low;
	int j = mid;
	int k = low;
	
	while (i < mid && j <= high)
	{
		if (nums[i] <= nums[j])
			temp[k++] = nums[i++];
		else
		{
			temp[k++] = nums[j++];
			inversions += mid - i;
		}
	}
	
	while (i < mid)
		temp[k++] = nums[i++];
	
	while (j <= high)
		temp[k++] = nums[j++];
	
	for (int i = low; i <= high; ++i)
		nums[i] = temp[i];
	
	return inversions;
}

ll merge_sort(int nums[], int temp[], int low, int high)
{
	ll inversions = 0;
	
	if (low < high)
	{
		int mid = low + ((high - low) >> 1);
		
		inversions += merge_sort(nums, temp, low, mid);
		inversions += merge_sort(nums, temp, mid + 1, high);
		
		inversions += merge(nums, temp, low, mid + 1, high);
	}
	
	return inversions;
}

ll merge_sort(int nums[], int n)
{
	int *temp = new int[n];
	return merge_sort(nums, temp, 0, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		int nums[n];
		
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		
		cout << merge_sort(nums, n) << "\n";
	}
	
	return 0;
}