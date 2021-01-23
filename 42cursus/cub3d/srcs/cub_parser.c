#include "cub3d.h"

static int
	cub_validate(int mode, char *check, t_cub *cub3d)
{
	if (mode == 1)
	{
		if (cub_prs_one(check, cub3d))
			panic("invalid resolution argument");
	}
	else if (mode >= 21 && mode <= 25)
	{
		if (cub_prs_two(mode, check, cub3d))
			panic("invalid texture argument");
	}
	else if (mode >= 31 && mode <= 32)
	{
		write(1, "color", 5);
		write(1, "\n", 1);
	}
	else if (mode == 4)
	{
		write(1, "map", 3);
		write(1, "\n", 1);
	}
	else if (mode == 5)
	{
		write(1, "qqqq", 4);
		write(1, "\n", 1);
	}
	return (0);
}

static void
	cub_validator(char *check, t_cub *cub3d)
{
	int		i;
	int		mode;

	if (!check)
		panic("null line");
	i = 0;
	while (check[i])
	{
		if (check[i] == ' ' || check[i] == '\t')
			;
		else if ((mode = cub_issomething(check[i], check[i+1])))
		{
			cub_validate(mode, &check[i+2], cub3d);
			if (mode != 0)
				break ;
		}
		i++;
	}
}

void
	cub_file_parser(char *file)
{
	t_cub	cub3d;
	char	*line;
	int		fd;

	if (!file)
		panic("no file");
	cub_initstruct(&cub3d);
	if ((fd = open(file, O_RDONLY)) < 0)
		panic("invalid file");
	while (get_next_line(fd, &line))
		cub_validator(line, &cub3d);
	cub_validator(line, &cub3d);
	
	puts(cub3d.no);
	puts(cub3d.so);
	puts(cub3d.we);
	puts(cub3d.ea);
	
	//printf("width: %d, height: %d\n", cub3d.width, cub3d.height);
	//printf("no: %s\nso: %s\nwe: %s\nea: %s\ns: %s\n", cub3d.no, cub3d.so, cub3d.we, cub3d.ea, cub3d.s);
}
