#include <stdio.h>

int main()
{
	unsigned char a = 0xff;
	signed char b = 0xff;
	char c = 0xff;
	printf("%2.2x\n%2.2x\n%2.2x\n", a, b, c);

	return 0;
}
