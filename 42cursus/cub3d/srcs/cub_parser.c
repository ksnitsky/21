#include "cub3d.h"

static int
	cub_validate(int mode, char *check, t_cub *cub3d)
{
	if (mode == 1)
	{
		if (cub_prs_reso(check, cub3d))
			panic("invalid resolution argument");
	}
	else if (mode >= 21 && mode <= 25)
	{
		if (cub_prs_textures(mode, check, cub3d))
			panic("invalid texture argument");
	}
	else if (mode >= 31 && mode <= 32)
		cub_prs_colors(mode, check, cub3d);
	else if (mode == 4)
	{
		if (!cub3d->f || !cub3d->c)
			panic("invalid color argument");
		if (cub_prs_map(check, cub3d))
			panic("invalid map");
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
			if (mode == -1)
				panic("unexpected error");
			else if (mode == 4)
				cub_validate(mode, check, cub3d);
			else
				cub_validate(mode, &check[i+2], cub3d);
			if (mode != 0)
				break ;
		}
		i++;
	}
	free(check);
}

void
	cub_file_parser(char *file, t_cub *cub3d)
{
	char	*line;
	int		fd;

	if (!file)
		panic("no file");
	if ((fd = open(file, O_RDONLY)) < 0)
		panic("invalid file");
	while (get_next_line(fd, &line))
		cub_validator(line, cub3d);
	cub_validator(line, cub3d);
}
