#include <stdio.h>

typedef union {
    signed long int value1;
    char name;
    double Double; 
    float value2;
} structure;

int main()
{
    structure data;

    printf("union size: %ld \n", sizeof(data));

    return 0;
}