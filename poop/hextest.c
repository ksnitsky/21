#include <stdio.h>

int
	main(void)
{
	int color = 0x0;
	int test = 0x0;

	color = (220<<16) | (100<<8) | (30<<0);
	test = (225<<16) | (30<<8) | (100<<0);

	printf("%x, %x", color, test);
}
