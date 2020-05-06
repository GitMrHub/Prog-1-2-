#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 120

int main() {
	int i=1;
	char sent[MAX], *pw, delim[]=", =", *q, *pb;
	puts("Enter the sent: ");
	gets(sent);
	printf("\n");
	pw=strtok(sent, delim);
	do{ 
	 	if (isdigit(*pw)  || *pw =='-'){ 
	 		for(q=pw; *q!='\0'; q++){
					if(*q=='.'){
						printf("%s = ", (pb));
						printf("%%f\n");
						i=0;
					}
				}
			if(i){
			printf("%s = ", (pb));
			printf("%%d\n");	
			}	
	 	}
	 	if(*pw == '\''){
	 		printf("%s = ", (pb));
			printf("%%c\n");	
		 }
		i=1;
	 	pb=pw;
 		pw=strtok(NULL,delim);
 	}while(pw!=NULL);
	getch();
	return 0;
}
