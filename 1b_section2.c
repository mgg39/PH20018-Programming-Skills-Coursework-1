//
// Created by Maria on 08/03/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double** read_file(char* filename, int N)
{
    FILE *fp = fopen(filename , "r");
    //null stuff
    double** result = (double **)malloc(2*sizeof(double*));
    double * x = (double *)malloc(N*sizeof(double));
    double * j1 = (double *)malloc(N*sizeof(double));
    if (!result || !x|| !j1)
    {
        fprintf(stderr, "\n Malloc  error\n");
        exit(-1);
    }
    //*ignores
    //EOF ends while loop
    //extra security N size
    int i =0;
    while (fscanf(fp, "%lf, %*lf, %lf, %*lf\n", &x[i], &j1[i]) != EOF && i<N)
    {
        i++;
    }
    result[0]=x;
    result[1]=j1;
    
    fclose(fp);

    return result;
}

double I(double x,double j1){
    //Io=1
        double eqt = 2 * j1 / x;
        double result = pow(eqt, 2);
        return result;

}


int main()
{
    double **test=read_file("data1b_part1.txt", 1000);
    int i;
    FILE* fp2 = fopen("data1b_part2.txt", "w");
    if (!fp2)
    {
        fprintf(stderr, "Failed to open file");
        exit(-1);
    }
    for (i = 0; i < 1000; ++i)
    {
        double data = I(test[0][i], test[1][i]);
        fprintf(fp2,"%lf\t%lf\n", data , test[0][i]);
    }

    //closing file & free arrays
    fclose(fp2);
    free(test[0]);
    free(test[1]);
    free(test);
    return 1;

}