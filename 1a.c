#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

//define the function f(x)
double f(double theta, double x, double m)
{
	double result;
	result = cos(m * theta - x * sin(theta));
	return result;
}
double f_wrapper(double *params)
{
	// Returns value of f(m, x, theta), theta is in 0th pos ie variable the integration occurs over.
	return f(params[0], params[1], params[2]);
}

//linear space construction
double *linspace(double start, double stop, int N)
{
	double *result = (double *)malloc(N * sizeof(double));
	if (!result)
	{
		fprintf(stderr, "Failed malloc");
		exit(-1);
	}
	if (stop < start)
	{
		fprintf(stderr, "Endpoint & startpoint error");
		exit(-1);
	}
	double current = start, dx = (double)(stop - start) / N;
	int i;
	for (i = 0; i < N; ++i)
	{
		result[i] = current;
		current = current + dx;
	}
	return result;
}

//integration function
double integrate(double (*func)(double *), double *params, double a, double b, int N)
{

	double *range = linspace(a, b, N);
	if (b < a)
	{
		fprintf(stderr, "Endpoint & startpoint error");
	}
    //calculating h
    double h = (b - a) / N;

	double y0_params[] = {a, params[1], params[2]};
	double yn_params[] = {b, params[1], params[2]};

	double y0 = func(y0_params);
	double yn = func(yn_params);

	double sum = (y0 + yn) / 2;

	int i;
	for (i = 0; i < N; ++i)
	{
		params[0] = range[i];
		sum = sum + func(params);
	}

	double result = h * sum;
	
	return result;

}

//calculate the integral
double J(double x, double m, int N)
{
	double params[] = {0., x, m}; 
	double area = integrate(f_wrapper, params, 0, M_PI, N);
    //divide by pi and return the integration result
    double result = area / M_PI;
	return result;
}

int main()
{
	
	int N = 1000;
	double *x_range = linspace(0, 20, N);
	double **y_vals = (double **)malloc(3 * sizeof(double *));
	double *y_vals_0 = (double *)malloc(N * sizeof(double));
	double *y_vals_1 = (double *)malloc(N * sizeof(double));
	double *y_vals_2 = (double *)malloc(N * sizeof(double));
		
	y_vals[0] = y_vals_0;
	y_vals[1] = y_vals_1;
	y_vals[2] = y_vals_2;

	int i, m;
	for (m = 0; m < 3; ++m)
	{
		printf("\nm = %d", m);
		for (i = 0; i < N; ++i)
		{
			y_vals[m][i] = J(x_range[i], m, 10000);
		}
	}
	//file fprintf for data analysis & modelling
	putchar('\n');
	FILE *fp = fopen("data1a.txt", "w");
	if (!fp)
	{
		fprintf(stderr, "Failed to open file");
		exit(-1);
	}
	for (i = 0; i < N; ++i)
	{

		fprintf(fp, "%lf, %lf, %lf, %lf\n", x_range[i], y_vals[0][i], y_vals[1][i], y_vals[2][i]);

	}
	//close file 
	fclose(fp);
	return 1;
}

