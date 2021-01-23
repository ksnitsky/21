#include <stdio.h>

int
	main(void)
{
	int red = 0x0;
	int green = 0x0;
	int blue = 0x0;
	int color = 0x0;

	red += 220;
	green += 20;
	blue += 60;
	color = (red<<16) | (green<<8) | (blue);

//	pook = pook * 100 +  0x14;
	printf("%x", color);
}
