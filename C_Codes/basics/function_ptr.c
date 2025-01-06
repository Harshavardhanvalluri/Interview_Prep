#include <stdio.h>

typedef int (*add_callback)(int , int);

int add( int a , int b )
{   return (a + b); }

int main()
{
    add_callback cb = add;

    printf("%d \n", cb( 10 ,20 ));

    return 0;
}