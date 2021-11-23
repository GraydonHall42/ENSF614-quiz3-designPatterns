# include <stdio.h>

int main(void)
{
    int a = 0, b =0;
    printf("Please etner a value for variable a: \n");
    scanf("%d", &a);
    printf("Please etner a value for variable b: \n");
    scanf("%d", &b);
    printf("The values of a and b are %d for a and %d for b.\n", a, b);
    printf("The value of a%%b is %d", a % b);

    // note: scanf returns the number of items it has read sucessfully

    /*
    Format specifiers
    int - %d
    float - %f
    double - %lf
    char - %c
    long int - %ld 
    string - %s
     */


}