/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 12:07:42 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/13 13:59:26 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <dirent.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft.h"
# include "SDL.h"

# define MIN_DIST_FOG 2
# define MAX_DIST_FOG 10
# define MIN_VALUE_FOG 1
# define MAX_VALUE_FOG 0.2
# define GREY 0x80, 0x80, 0x80
# define L_LVL e->max_loglvl
# define W_LVL (seek_lvl(e))
# define O_MOV(x) can_move(W_LVL x, e)
# define SIZE_H 900
# define SIZE_L 1300
# define KEY ev.key.keysym.sym
# define MV_SPEED frame_time * 5.0
# define ROT_SPEED frame_time * 3.0

# define HELL1 O_MOV([(int)(e->pos.x + e->dir.x * MV_SPEED)][(int)e->pos.y])
# define HELL2 O_MOV([(int)(e->pos.x)][(int)(e->pos.y + e->dir.y * MV_SPEED)])
# define HELL3 O_MOV([(int)(e->pos.x - e->dir.x * MV_SPEED)][(int)e->pos.y])
# define HELL4 O_MOV([(int)(e->pos.x)][(int)(e->pos.y - e->dir.y * MV_SPEED)])

typedef struct dirent	t_fil;

typedef struct	s_pnt
{
	double	x;
	double	y;
}				t_pnt;

typedef struct	s_ipnt
{
	int		x;
	int		y;
}				t_ipnt;

enum
{
	DOWN = 0,
	UP,
	LEFT,
	RIGHT
};

typedef struct	s_env
{
	char		kb[4];
	void		*sdl_wdw;
	void		*sdl_buf;
	t_list		*levels;
	t_pnt		pos;
	t_pnt		dir;
	t_pnt		plane;
	double		time;
	double		old_time;
	int			max_loglvl;
	int			current_lvl;
}				t_env;

typedef struct	s_ray
{
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			hit;
	int			side;
	t_ipnt		map;
	t_ipnt		step;
	t_pnt		ray_pos;
	t_pnt		ray_dir;
	int			color;
	size_t		x;
	double		fog;
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
void			ft_move(t_env *e);
void			ft_spawn(t_env *e, int level);
int				can_move(int i, t_env *e);

#endif
