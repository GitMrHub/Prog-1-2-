#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



int main() 
{
	float eps;
	int n, i;
	do
	{
		printf("EPS = ");
		scanf("%f", &eps);
	}while (eps<=0 || eps>=1);
	printf("n = ");
	scanf("%d", &n);
	float a[n], b[n];
	printf("\n\n");
	for (i=0; i< n; i++)
	{
		printf("Input a[%d] = ",i); 
		scanf("%f", &a[i]);
	}
	printf("\n\n");
	for (i=0; i< n; i++)
	{
		printf("Input b[%d] = ",i); 
		scanf("%f", &b[i]);
	}
	printf("\n\n");
	for (i=0; i< n; i++)
	{
		printf("%3.2f ", a[i]);
	}
	printf("\n\n");
	for (i=0; i< n; i++)
	{
		printf("%3.2f ", b[i]);
	}	
	printf("\n\n");
	for (i=0; i<n; i++)
	{
		if(fabs(a[i])<eps)
		{
			a[i]=b[i];
		}
	}
	for (i=0; i< n; i++)
	{
		printf("%3.2f ", a[i]);
	}	
	getch();
	return 0;
}
