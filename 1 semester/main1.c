#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100


int main() 
{
	int i=0;
	char sent[MAX], *p, *q, *b;
	
	b=(char*)malloc(MAX * sizeof(char));
	puts("Enter the sent: ");
	gets(sent);
	printf("\n");
	
	for(p=sent; *p!='\0'; p++)
	{
		if(*p!='=')
		{
			b[i]=*p;
			i++;
		}
		else
		{
			b[i]='\0';
			p++;
			if( isdigit(*p) || (*p=='-') )
			{
				for(q=p; *q!=','; q++)
				{
					if(*q=='.')
					{
						printf("%%f = ");
						puts(b);
						i=0;
					}
					if(*q=='e')
					{
						printf("%%e = "); 
						puts(b);
						i=0;
						
					}
				}
				if(i)
				{
					printf("%%d = "); 
					puts(b);
					i=0;
				}
				p=q;	
			}
			else
			{
				printf("%%c = "); 
				puts(b);
				p=p+3;
				i=0;	
			}
			free(b);
		} 
	}
	getch();
	return 0;
}
