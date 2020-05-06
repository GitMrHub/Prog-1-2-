#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char operation(char a);
double vuraz(double x, double y, char (*pf)(char(a)));

int main() {
	char a;
	double x,y;
	printf("enter x and y: ");
	scanf("%lf%lf", &x, &y);
	printf("%lf", vuraz(x, y, operation));
	return 0;
}

char operation(char a){
	printf("Chooce operation: (+ - * /)");
	scanf("%c", a);
	return a;
}

double vuraz(double x, double y, char (*pf)(char(a))){
	if( operation =='+'){
		return pow((x+y), 2);
	}
	
}	
