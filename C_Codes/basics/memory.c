#include <stdio.h>

volatile int sensor_reading;

int main()
{
    int x = 5;
    int y = 10;
    const int *ptr = &x;  // Pointer to constant integer
    ptr = &y;             // Valid, pointer can point to a different address
    //*ptr = 20;          // Invalid, attempting to modify the value pointed to

    printf("%d \n", *ptr );


    printf("Size of pointers\n");
    printf("Sizeof(void*) : %ld\n", sizeof(void*) );
    printf("Sizeof(int*) : %ld\n", sizeof(int*) );
    printf("Sizeof(char*) : %ld\n", sizeof(char*) );
    printf("Sizeof(long*) : %ld\n", sizeof(long*) );
    printf("Sizeof(float*) : %ld\n", sizeof(float*) );
    printf("Sizeof(double*) : %ld\n", sizeof(double*) );

    return 0;
}