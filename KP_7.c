#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double division (double x);
double sum(int n, double a, double b, double (*pf)(double(x)));
double integral(double a, double b, double eps, double (*pf)(double(x)));

int main(){
	double eps, a=0, b=6, x, res;
	res = integral(a, b, eps, division);
	printf ("Integral = %lf\n", res);
	return 0;
}

double division (double x){
	return 1./sqrt(1+x*x*x*x);
}

double sum(int n, double a, double b, double (*pf)(double(x))){
	double dx = fabs(b-a)/n, s=0;
	int i=0;
	for(; i<n; i++, a+=dx){
		s+=dx*(*pf)(a);
	}
	return s;
}

double integral(double a, double b, double eps, double (*pf)(double(x))){
	double s1, s2, ds;
	int n;
	puts("enter n, eps\n");
	scanf("%d%lf", &n, &eps);
	s1 = sum(n, a, b, pf);
	do{
		n*=2;
		s2 = sum(n, a, b, division);
		ds = fabs(s1-s2);
		s1=s2;
	}while(ds>eps);
	return s1;
}


