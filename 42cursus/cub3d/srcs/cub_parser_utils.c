#include "cub3d.h"

int
	cub_store_colors(char *rgb)
{
	int		hexcolor;
	int		temp;
	int		byte;

	byte = 16;
	hexcolor = 0x0;
	temp = 0;
	while (*rgb)
	{
		if (ft_isdigit(*rgb))
			temp = (temp * 10) + (*rgb - 48);
		rgb++;
		if (*rgb == ',' || *rgb == '\0')
		{
			hexcolor |= (temp<<byte);
			byte -= 8;
			temp = 0;
		}
	}
	return (byte == -8 ? hexcolor : 0);
}
