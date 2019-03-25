#include <stdio.h>

main()
{
printf("\n");
printf("sizeof(char)=%ld byte\n", sizeof(char));
printf("sizeof(int)=%ld bytes\n", sizeof(int));
printf("sizeof(long)=%ld bytes\n", sizeof(long));
printf("sizeof(float)=%ld bytes\n", sizeof(float));
printf("sizeof(double)=%ld bytes\n", sizeof(double));
printf("sizeof(char *)=%ld bytes\n", sizeof(char *));
printf("sizeof(float *)=%ld bytes\n", sizeof(float *));
printf("sizeof(float **)=%ld bytes\n", sizeof(float **));
}
