/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 19:25:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/04 16:48:13 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_env(t_env *e, int ac, char **av)
{
	if (ac > 1 && !ft_strcmp(av[1], "-xv"))
		L_LVL = L_DEBUG;
	else if (ac > 1 && !ft_strcmp(av[1], "-v"))
		L_LVL = L_INFO;
	else
		L_LVL = L_WARNING;
	e->pos.x = 22;
	e->pos.y = 12;
	e->dir.x = -1;
	e->dir.y = -1;
	e->plane.x = 0;
	e->plane.y = 0.66;
	ft_logger(L_LVL, 2, L_INFO, "Environment Initialized");
}
