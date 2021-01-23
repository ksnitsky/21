#include "cub3d.h"

int
	main(int argc, char **argv)
{
	if (argc == 1)
		panic("map file required");
	else
		cub_file_parser(argv[1]);
	//cub_image_painter();
	return (0);
}
