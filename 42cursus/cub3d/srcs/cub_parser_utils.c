#include "cub3d.h"

int
	cub_prs_one(char *check, t_cub *cub3d)
{
	int		space;
	
	space = 0;
	while (*check)
	{
		if (ft_isdigit(*check))
			if (!space)
				cub3d->width = (cub3d->width * 10) + (*check - 48);
			else
				cub3d->height = (cub3d->height * 10) + (*check - 48);
		else if (*check == ' ' && cub3d->width)
			space = 1;
		check++;
	}
	if (!cub3d->width || !cub3d->height)
		return (1);
	return (0);
}

int
	cub_prs_two(int mode, char *check, t_cub *cub3d)
{
	int		index;

	index = 0;
	while (check[index] == ' ' || check[index] == '\t')
		index++;
	if (mode == 21 && !cub3d->no)
		cub3d->no = &check[index];
	else if (mode == 22 && cub3d->no)
		cub3d->so = &check[index];
	else if (mode == 23 && cub3d->so)
		cub3d->we = &check[index];
	else if (mode == 24 && cub3d->we)
		cub3d->ea = &check[index];
	else if (mode == 25 && !cub3d->s)
		cub3d->s = &check[index];
	else
		if (!cub3d->no || !cub3d->so || !cub3d->we || !cub3d->ea)
			return (1);
	return (0);
}
/*
int
	cub_prs_three(char *check, t_cub *cub3d)
{

}
*/