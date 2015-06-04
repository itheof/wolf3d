/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 12:07:42 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/04 17:06:01 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <dirent.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft.h"

# define L_LVL e->max_loglvl
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
}				t_env;

void			set_env(t_env *e, int ac, char **av);
t_list			*load_levels(char *av, t_env *e);

void			expose_hook(void *param);
void			key_hook(int keycode, void *param);
void			loop_hook(void *param);

void			draw(t_env *e);

#endif
