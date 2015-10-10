/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 19:25:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/13 14:18:43 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_env(t_env *e, int ac, char **av)
{
	if (ac > 1 && !ft_strcmp(av[1], "-xv"))
		L_LVL = L_DEBUG;
	else if (ac > 1 && !ft_strcmp(av[1], "-v"))
		L_LVL = L_INFO;
	else
		L_LVL = L_WARNING;
	e->current_lvl = 0;
	e->old_time = 0;
	e->time = 0;
	e->kb[0] = 0;
	e->kb[1] = 0;
	e->kb[2] = 0;
	e->kb[3] = 0;
	ft_logger(L_LVL, 2, L_INFO, "Environment initialized");
}

static void	ft_find(int **tab, int *i, int *j)
{
	int	ti;
	int	tj;

	ti = 0;
	tj = 0;
	while (tab[ti] && tab[ti][tj] != 5)
	{
		tj = 0;
		while (tab[ti][tj] && tab[ti][tj] != 5)
			tj++;
		if (tab[ti][tj] == 5)
		{
			*i = ti;
			*j = tj;
			return ;
		}
		ti++;
	}
	*i = 0;
	*j = 0;
}

void		ft_spawn(t_env *e, int level)
{
	int	i;
	int	j;

	e->dir.x = -1;
	e->dir.y = 0;
	e->plane.x = 0;
	e->plane.y = 0.66;
	e->current_lvl = level;
	if (W_LVL == NULL)
	{
		ft_logger(L_LVL, 2, L_INFO, "All levels cleared.");
		ft_exit(e);
	}
	ft_find(W_LVL, &i, &j);
	e->pos.x = i;
	e->pos.y = j;
	if (W_LVL[i] && W_LVL[i][j] == 5)
		ft_logger(L_LVL, 2, L_INFO, "Spawned");
	else
	{
		ft_logger(L_LVL, 2, L_WARNING,
				"Cannot spawn on this level, skipping");
		ft_spawn(e, level + 1);
	}
}
