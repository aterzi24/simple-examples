#include <stdio.h>

union Data
{
	int a;
	int b;
}src;

int main()
{
	src.a = 5;
	printf("%d %d\n", src.a, src.b); /* prints 5 5 */
	return 0;
}
