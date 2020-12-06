#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


int main() 
{
	int n, m, i, j, k, min, max, voice, fl=1, temp;
	printf("enter m: \n");
	scanf("%d", &m);
	printf("enter n: \n");
	scanf("%d", &n);
	int a[m][n];
	printf("Random?\n1-yes/2-no: \n");
	scanf("%d", &voice);
	switch(voice)
	{
	case(1):                                         // Çàäàºìî ìàñèâ A ðàíäîìîì
		srand(time(NULL));
		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				a[i][j]=rand()%100;
				printf("%6d", a[i][j]);	
			}
			printf("\n");		
		}
		break;	
	case(2):                                           // Çàäàºìî ìàñèâ A â³ä ðóêè
		for(i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				printf("Input a[%d][%d] = ",i ,j); 
				scanf("%d", &a[i][j]);
			}
		}
		for(i=0; i<m; i++)                             // âèâîäèìî çàäàíèé â³ä ðóêè ìàñèâ
		{
			for(j=0; j<n; j++)
			{
				printf("%6d", a[i][j]);
			}
			printf("\n");
		}
		break;
	default:
		printf("ERROR\n");
	}
	printf("\n");
	printf("\n");
	for (i=0; i<m; i++)
	{
		if (fl>0)
		{
			for(k=0; k<=n-1; k++)
			{
				min=k;
				j=k+1;
				for(j; j<n; j++)
				{
					if(a[i][j]<a[i][min])
					{
						min=j;
					}
				}
				temp=a[i][k];
				a[i][k]=a[i][min];
				a[i][min]=temp;
			}
		}
		if(fl<0)
		{
			for(k=0; k<=n-1; k++)
			{
				max=k;
				j=k+1;
				for(j; j<n; j++)
				{
					if(a[i][j]>a[i][max])
					{
						max=j;
					}
				}
				temp=a[i][k];
				a[i][k]=a[i][max];
				a[i][max]=temp;
			}			
		}
		fl=-fl;
	}
	for(i=0; i<m; i++)                             // âèâîäèìî íîâûé ìàñèâ
	{
		for(j=0; j<n; j++)
		{
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}
