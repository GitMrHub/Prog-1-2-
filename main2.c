#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main() 
{
	int n, m, i, max, k=0, j=0,v;
	printf("Input dimention of array: ");
	scanf("%d", &n);
	int  a [n], b[n];
	printf("Random?\n1-yes/2-no: \n");
	scanf("%d", &v);
	switch(v)                                                  // Выбираем как задать массив
	{
	case(1):
		srand(time(NULL));                                     // Рандом
		for (i=0; i<n; i++)
			{
				a[i]= rand() % 100;
				printf("%d ", a[i]);	
			}
			printf("\n");	
		break;	
	case(2):                                                    // Массив задает Пользователь
		for(i=0; i < n; i++)
			{
				printf("Input a[%d] = ", i); 
				scanf("%d", &a[i]);
			}
		for(i=0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
		break;
	default :
		printf("error\n");
		break;
	}
	printf("\n\n");
	for(i=0; i < n; i++)                             // ищем мака последовательность нулей
	{
		if (a[i]==0)
		{
			k++;
			b[j]=k;	
			if (a[i+1]!=0)
			{
				k=0;
				j++;	
			}
		}
	}
	for (; j<n; j++)
	{
		b[j]=0;
	}
	max=b[0];
	for(j=0; j < n; j++)
	{
		if (max<b[j])
		{
			max = b[j];
		}
	}
	for(i=0; i < n; i++)
	{
		if (a[i]==0)
		{
			printf("Max zeros in array = %d",max);
			break;
		}	
	}
	getch();
	return 0;
}
