#include <stdio.h>

//#define STRUCT_PAD_4BYTES
#define STRUCT_PAD_1BYTES

#if defined(STRUCT_PAD_4BYTES)
typedef struct __attribute__((packed, aligned(4))) {
    signed long int value1;
    char name;
    double Double; 
    float value2;
} structure;
#elif defined(STRUCT_PAD_1BYTES)
typedef struct __attribute__((packed, aligned(1))) {
    signed long int value1;
    char name;
    double Double; 
    float value2;
} structure;
#else
typedef struct {
    signed long int value1;
    char name;
    double Double; 
    float value2;
} structure;
#endif

int main()
{
    printf("Size: %ld \n", sizeof(structure));
    printf("Size (signed long int): %ld \n", sizeof(signed long int));
    printf("Size (char): %ld \n", sizeof(char));
    printf("Size (float): %ld \n", sizeof(float));
    printf("Size (Double): %ld \n", sizeof(double));

    return 0;
}
