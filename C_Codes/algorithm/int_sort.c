#include <stdio.h>

void print_sort( int *sort_src, int size )
{
    for (size_t i = 0; i < size; i++)
    {
        printf( "%d ,", sort_src[i]);
    }
    printf("\n");
}

/// @brief  Bubble sort function
/// @param sort_src sort input
/// @param len sort input length
/// @return 
void sort( int *sort_src , int len)
{
    for (size_t i = 0; i < len ; i++)
    {
        for (size_t j = i; j < len; j++)
        {
            if ( sort_src[j] < sort_src[i] )
            {
                /// Swap values
                int swap = sort_src[i];
                sort_src[i] = sort_src[j];
                sort_src[j] = swap;
            }
        }
    }
    
    return;
}

int main()
{
    int sort_src[] = { 101, 11 , 9 , 21, 1, 4, 33, 88 };

    print_sort( sort_src , (sizeof(sort_src)/sizeof(int)) );

    sort( sort_src , (sizeof(sort_src)/sizeof(int)));

    print_sort( sort_src , (sizeof(sort_src)/sizeof(int)) );

    return 0;
}