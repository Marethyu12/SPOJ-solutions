#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int t;
	int N;
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d", &N);
		
		int nums[2][N];
		int hot = 0;
		
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &nums[i][j]);
		
		qsort((void *) nums[0], N, sizeof(int), cmp);
		qsort((void *) nums[1], N, sizeof(int), cmp);
		
		for (int i = 0; i < N; ++i)
			hot += nums[0][i] * nums[1][i];
		
		printf("%d\n", hot);
	}
	
	return 0;
}