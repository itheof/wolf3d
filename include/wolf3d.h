/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 12:07:42 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/08 18:26:42 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <dirent.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft.h"

# define L_LVL e->max_loglvl
# define W_LVL (seek_lvl(e))
# define SIZE_H 600
# define SIZE_L 600

typedef struct dirent	t_fil;

typedef struct	s_pnt
{
	double	x;
	double	y;
}				t_pnt;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*wdw_ptr;
	void		*img_ptr;
	t_list		*levels;
	t_pnt		pos;
	t_pnt		dir;
	t_pnt		plane;
	double		time;
	double		old_time;
	int			max_loglvl;
	size_t		current_lvl;
}				t_env;

typedef struct	s_ray
{
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			hit;
	int			side;
	t_pnt		map;
	t_pnt		step;
	t_pnt		ray_pos;
	t_pnt		ray_dir;
	int			color;
	size_t		x;
}				t_ray;

void			set_env(t_env *e, int ac, char **av);
t_list			*load_levels(char *av, t_env *e);
int				**seek_lvl(t_env *e);

int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
int				loop_hook(void *param);


void			draw(t_env *e);
void			raycast(size_t x, t_ray *ray, t_env *e);
void			ft_exit(t_env *e);

#endif
