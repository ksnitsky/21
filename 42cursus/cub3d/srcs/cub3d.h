#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include "libft.h"

# define HEX_BASE "0123456789abcde"

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_cub
{
	int			width;	//res
	int			height;	//res
	char		*no;	//text north
	char		*so;	//text south
	char		*we;	//text west
	char		*ea;	//text east
	char		*s;		//text sprit
	int			f;		//color floor
	int			c;		//color ceiling
	char		**map;	//map
}				t_cub;

// painter
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			cub_image_painter();

// utils
void			cub_initstruct(t_cub *cub3d);
void			panic(char *msg);
int				cub_issomething(char c1, char c2);
char			*cub_strjoin(char *s1, char *s2);

// parser
void			cub_file_parser(char *file, t_cub *cub3d);
int				cub_prs_reso(char *check, t_cub *cub3d);
int				cub_prs_textures(int mode, char *check, t_cub *cub3d);
int				cub_prs_colors(int mode, char *check, t_cub *cub3d);
int				cub_prs_map(char *check, t_cub *cub3d);

// parser utils
int				cub_store_colors(char *rgb);

#endif
