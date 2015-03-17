/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:21:53 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/17 16:58:46 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include "libft.h"

typedef struct  s_env
{
    void        *mlxptr;
    void        *win;
    int         **map;
    int         pos_x;
    int         pos_y;
    int         cam_a;
}               t_env;

int     **ft_map(char *file);
void    draw(t_env *e);

#endif
