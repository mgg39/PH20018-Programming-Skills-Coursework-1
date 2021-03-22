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
    int accuracy = pow(10, 6);
    int value_end = 4 * accuracy;
    int value_start = -7 * accuracy;
    

        //file fprintf for data analysis & modelling
        putchar('\n');
        FILE* fp = fopen("data_question3.txt", "w");
        if (!fp)
        {
            fprintf(stderr, "Failed to open file");
            exit(-1);
        }
        for (i = value_start; i < value_end; ++i)
        {
            double recalc_value = (double)i / (double)accuracy;
            // x corresponds to recalc value
            double positive_f2 = 0.5 * (f2(recalc_value) - recalc_value);
            double negative_f2 = 0.5 * (-f2(recalc_value) - recalc_value);
            double f1_value_positive = f1(recalc_value) - 1;
            double f1_value_negative = -f1(recalc_value) - 1;

            //printf("\t %d \t %f \n", i, recalc_value);
            //printf(" \t %f \n", f1(0.2));
            fprintf(fp, "%lf, %lf, %lf, %lf, %lf\n", recalc_value, positive_f2, negative_f2, f1_value_positive, f1_value_negative);
        
            //finding the answers through comparison 
            comparison(recalc_value, f1_value_positive, positive_f2, accuracy);
            comparison(recalc_value, f1_value_positive, negative_f2, accuracy);
            comparison(recalc_value, f1_value_negative, positive_f2, accuracy);
            comparison(recalc_value, f1_value_negative, negative_f2, accuracy);

        }


      fclose(fp);
      return 1;
}
