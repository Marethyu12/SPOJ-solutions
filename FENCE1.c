#include <stdio.h>
#include <math.h>

int main(void)
{
	int L;
	double area;
	
	while (1)
	{
		scanf("%d", &L);
		
		if (L == 0)
			break;
		
		//By bending fence of length L into a semicircle, it will produce a largest enclosed area.
		//The semicircle area formula in terms of L is: A=(L^2)/2*PI
		area = pow(L, 2.0) / (2 * M_PI);
		
		printf("%.2f\n", area);
	}
	
	return 0;
}