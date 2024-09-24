#include <stdio.h>
#include <math.h>
/*
* Steps:
* i) Find the coefficients
* ii) Find mean
* iii) find f(x)
*
*/

double f(double x, int degree, float* coef){
	
	double fx = 0;

	for(int i = 0; i <= degree; i++){
		fx += coef[i] * pow(x, degree - i);
	}

	return fx;
}

void find_initial_coef(double* a, double* b, int order, float* coef){
	
	for(int i=0; i < 1000; i++){
		        *a = i;               
        *b = i + 1;           
        double fa = f(*a, order, coef);
        double fb = f(*b, order, coef);
        if (fa > 0 && fb < 0 || fa < 0 && fb > 0) {
            return;          
        }

	}
}

double mean(double a, double b){

	return (a + b) /2;
}


int main(){

	int order;
	int iter;
	double a,b;
	float coef[100];

	printf("Enter the order of equation: ");
	scanf("%d",&order);

	printf("Enter the coefficient in decreasing order \n");
	for(int i = 0; i <= order; i++){
		printf("Coeffiecient of order %d : ",order-i);
		scanf("%f", coef+i);
	}

	printf("How many iteration do you want to perform: ");
	scanf("%d", &iter);

	find_initial_coef(&a, &b, order, coef);

	 double mean_value = mean(a, b);
    double fx = f(mean_value, order, coef);
    for (int i = 0; i < iter; i++) {  
        if (fx < 0) {
            a = mean_value;  
        } else {
            b = mean_value;  
        }
        mean_value = mean(a, b);  
        fx = f(mean_value, order, coef);  
    }

	printf("\nThe final answer is %lf", mean_value); 
}
