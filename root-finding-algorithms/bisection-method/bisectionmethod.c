#include <stdio.h>
#include <math.h>

#define EPSILON 0.01

void bisection(double (*func) (double), double a, double b){

	if((func(a) * func(b)) >= 0){
		printf("pls enter valid range of a and b\n");
		return;
	}

	double c = a;

	while ((b - a) >= EPSILON) {
		c = (a + b) / 2;

		if(func(c) == 0.0)
			break;
		else if(func(a) * func(c) < 0)
			b = c;
		else 
			a = c;
	
	}

  printf("The value of root is : %lf\n", c);

}

double func1(double x)
{
    return x*x*x - x*x + 2;
}

double func2(double x)
{
    return cos(x) - x * exp(x);
}


int main()
{
    double a1 = -200, b1 = 300;
    printf("Solving x^3 - x^2 + 2:\n");
    bisection(func1, a1, b1);

    double a2 = 0, b2 = 1;
    printf("\nSolving cos(x) - x * exp(x):\n");
    bisection(func2, a2, b2);

    return 0;
}
