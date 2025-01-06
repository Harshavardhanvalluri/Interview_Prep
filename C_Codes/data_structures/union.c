#include <stdio.h>

typedef union data_st{
    char data_2;
    char val;
}data_st;

int main()
{
    data_st data;

    printf("%d ", data.data_2);
    printf("%ld", sizeof(data));

    return 0;
}