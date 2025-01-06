#include <stdio.h>

#define CLEAR_BITS( val , pos ) ( ( (val) &= ~( 1 << (pos) ) ) )
#define SET_BITS( val , pos ) ( ( (val) |= ( 1 << (pos) ) ) )
#define TOGGLE_BITS( val , pos ) ( ( (val) ^= ( 1 << (pos) ) ) )

void printbits( unsigned char value , unsigned char size )
{
    for (int i = size * 8 - 1; i >= 0; i--) {
        printf("%d", (value & (1 << i)) ? 1 : 0);
    }
    printf("\n");
}

int set_bits( unsigned char value , unsigned char position )
{
    return ( value | ( 1 << (position -1 ) ) );
}

int clear_bits( unsigned char value, unsigned char position )
{
    return ( value & ~( 1 << (position - 1) ) );
}

int toggle_bits( unsigned char value, unsigned char position )
{
    return ( value ^ ( 1 << (position - 1) ) );;
}

int main() 
{
    unsigned char value = 0x01;

    printbits( value , sizeof( value ) );

    value = set_bits( value , 2 );

    printbits( value , sizeof( value ) );

    value = CLEAR_BITS( value , 2 );

    printbits( value , sizeof( value ) );

    ///value = toggle_bits( value , 2 );

    value = SET_BITS( value , 2 );

    value = TOGGLE_BITS( value , 2 );

    printbits( value , sizeof( value ) );

    return 0;
}