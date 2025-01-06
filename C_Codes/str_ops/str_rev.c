#include <stdio.h>
#include <string.h>

//// string reversal function

void str_reverse( const char* str_src , char *str_rev )
{
	if ( str_src == NULL || str_rev == NULL )
	{
		printf("Invalid input arguments\n");
		return;
	}


	int str_len = strlen(str_src);

	memset( str_rev , 0x0 , str_len );

	/// Start copying that string to the other pointer
	while ( str_len-- )
	{
		*str_rev++ = str_src[str_len];
	}
}

int main()
{
	const char* str1 = "Hello World 123";
	char str2[50];
	str_reverse( str1 , str2 );

	printf("%s \n", str2);
	return 0;
}