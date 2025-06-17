// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


int main() {
    unsigned int x = 4 , y = 3;
    
    // Write C code here
    printf("Array size: %d | %d \n", x , y);
    
    // 2 D array
    int **matrixarray = NULL;
    
    matrixarray = (int **)malloc(sizeof(int*) * x);
    if(matrixarray < 0)
    {
        printf("Memory allocation failed");
        return -1;
    }
    
    for( int i = 0; i < x ; i++)
    {
        matrixarray[i] = (int*)malloc(sizeof(int*) * y);
        if(matrixarray[i] < 0)
        {
            printf("Memory allocation failed");
            return -1;
        }
    }
    
    int counter = 0;
    for( int i = 0; i < x; i++)
    {
        int* matrix_row = matrixarray[i];
        for( int j = 0 ; j < y ; j++ )
        {
            matrix_row[j] = counter++;
        }
    }
    
    for( int i = 0; i < x; i++)
    {
        int* matrix_row = matrixarray[i];
        for( int j = 0 ; j < y ; j++ )
        {
            printf("matrix_row[%d][%d]: [%d] ", i , j, matrix_row[j]);
        }
        printf("\n");
    }
    

    return 0;
}
