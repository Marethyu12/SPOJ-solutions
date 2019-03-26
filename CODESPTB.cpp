#include <bits/stdc++.h>

using namespace std;

int merge_sort(int nums[], int temp[], int low, int high)
{
	if (low == high)
		return 0;
	
	int inversions = 0;
	
	int mid = (low + high) >> 1;
	
	inversions += merge_sort(nums, temp, low, mid);
	inversions += merge_sort(nums, temp, mid + 1, high);
	
	int i = low;
	int j = mid + 1;
	int k = low;
	
	while (i <= mid && j <= high)
		if (nums[i] <= nums[j])
			temp[k++] = nums[i++];
		else
		{
			temp[k++] = nums[j++];
			
			inversions += mid - i + 1;//note +1!
		}
	
	while (i <= mid)
		temp[k++] = nums[i++];
	
	while (j <= high)
		temp[k++] = nums[j++];
	
	for (int i = low; i <= high; ++i)
		nums[i] = temp[i];
	
	return inversions;
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
		
		int temp[n];
		
		cout << merge_sort(nums, temp, 0, n - 1) << "\n";
	}
	
	return 0;
}