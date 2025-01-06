#include <stdio.h>
#include <string.h>


void str_cat( char* str_src , const char* str_cat )
{
    if ( str_cat == NULL || str_src == NULL )
    {
        printf("Invalid input arguments\n");
        return;
    }

    /// find te string size and add the rest of the string
    int str_len = strlen( str_src );

    while ( *str_cat!= '\0' )
    {
        str_src[ str_len++ ] = *str_cat++;
    }
}

int main()
{
    char str1[50] = "Hello";
    char str2[] = " World";

    str_cat( str1, str2 );

    printf("Str: %s \n", str1);

    return 0;
}