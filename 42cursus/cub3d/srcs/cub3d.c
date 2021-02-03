#include "cub3d.h"

int
	main(int argc, char **argv)
{
	t_cub	cub3d;

	if (argc == 1)
		panic("map file required");
	else
	{
		cub_initstruct(&cub3d);
		cub_file_parser(argv[1], &cub3d);
	}
	printf("%x %x", cub3d.f, cub3d.c);
	//cub_image_painter();
	return (0);
}
