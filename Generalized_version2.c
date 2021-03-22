#include<stdio.h>
#include<math.h>
//used for absolute value function - fabs
#include<stdlib.h>


//defining function
double f(double x)
{
    double result;
    //calculation is done in radius
    result = pow(cos(x), 2) + pow(x, 3) - pow(x, 2) - 0.291064;
    //printf("\t\tf(%lf) = %lf\n", x, result);
    return result;
}

double root_finding(double (*f)(double x), double x0, double x1, double e, int N)
{
    int i = 0;
    double x2;
    if (e == 0.) 
    {
        printf("\nError cannot have an accuracy equal zero!\n");
        exit(-1);
    }
    if (x1 < x2 || x0==x1) 
    {
        printf("\nError range!\n");
        exit(-1);
    }
    //secant loop
    while (N > i++ && fabs(x1 - x0) > fabs(e)) 
    {
        x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - f(x0)));
        x0 = x1;
        x1 = x2;
        //printf("\t%d: %.20lf\n", i, x2);
    }
    return x2;
}



int main()
{
    //let's put a precision of 10^-6
    double e = 1 / pow(10, 6);

    int xmin_root2, xmax_root2, xmin_root1, xmax_root1;
    printf("For the first root. Please enter the maximum desired aproximation of x: \n");
    scanf("%d", &xmax_root1);
    printf("For the first root. Please enter the minimum desired aproximation of x: \n");
    scanf("%d", &xmin_root1);
    printf("For the secon root. Please enter the maximum desired aproximation of x: \n");
    scanf("%d", &xmax_root2);
    printf("For the second root. Please enter the minimum desired aproximation of x: \n");
    scanf("%d", &xmin_root2);

    if (xmin_root2 < xmax_root2 && xmin_root1 < xmax_root1)
    {
        double root = root_finding(f, xmin_root1, xmax_root1, e, 10000);
        printf("\n%lf\n", root);
        root = root_finding(f, xmin_root2, xmax_root2, e, 10000);
        printf("\n%lf\n", root);
    }
    else
    {
        printf("Range error");

    }


    return 1;
}