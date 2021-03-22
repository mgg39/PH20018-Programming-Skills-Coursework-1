#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//Standard Library of Complex Numbers
#include <complex.h>


//see work for why the use of these versions of the function
//defining function 1
double f1(double x)
{
    double equation;
    if (x < 4 && x >-6)
    {
         equation = sqrt(-pow(x, 2) - 2 * x + 24);
    }
    else {
         equation = sqrt(pow(x, 2) + 2 * x - 24) * I;
    }
    return equation;
}

//defining function 2
double f2(double x)
{
    double equation = sqrt(pow(x,2)+20);
    //double positive = 0.5*(-equation - x);
    //double negative = 0.5*(equation - x);
    return equation;
}

//function comparing obtained x 
double comparison(double x, double function_a, double function_b, double accuracy)
{

    double comparison_accuracy_factor = 10 / (accuracy);
    if (fabs(function_a - function_b) < comparison_accuracy_factor)
    {
        printf("%lf, \t %lf \n", x, function_a);
    }
    return 1;
}

int main()
{
    int i;
    int accuracy;
    int x_min;
    int x_max;
    printf("Desired accuracy: ");
    scanf("%d", &accuracy);
    printf("Max x: ");
    scanf("%d", &x_max);
    printf("Min x: ");
    scanf("%d", &x_min);
    int value_start = x_min * accuracy;
    int value_end = x_max * accuracy;

        //file fprintf for data analysis & modelling
    if (value_end < value_start)
    {
        printf("Error range");
    }
    else
    {
        for (i = value_start; i < value_end; ++i)
        {
            double recalc_value = (double)i / accuracy;
            // x corresponds to recalc value
            double positive_f2 = 0.5 * (f2(recalc_value) - recalc_value);
            double negative_f2 = 0.5 * (-f2(recalc_value) - recalc_value);
            double f1_value_positive = f1(recalc_value) - 1;
            double f1_value_negative = -f1(recalc_value) - 1;

            //finding the answers through comparison 
            comparison(recalc_value, f1_value_positive, positive_f2, accuracy);
            comparison(recalc_value, f1_value_positive, negative_f2, accuracy);
            comparison(recalc_value, f1_value_negative, positive_f2, accuracy);
            comparison(recalc_value, f1_value_negative, negative_f2, accuracy);

        }
     }


      return 1;
}
