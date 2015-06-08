/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:46:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/08 11:05:28 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_callbacks(t_env *e)
{
	ft_logger(L_LVL, 2, L_DEBUG, "Setting callbacks");
	mlx_key_hook(e->wdw_ptr, key_hook, e);
	mlx_expose_hook(e->wdw_ptr, expose_hook, e);
	mlx_loop_hook(e->wdw_ptr, loop_hook, e);
	ft_logger(L_LVL, 2, L_DEBUG, "calls set successfully");
}

int			main(int ac, char **av)
{
	t_env e;

	ft_logger(7, 2, L_INFO, "Initializing...");
	set_env(&e, ac, av);
	if (!(e.levels = load_levels(*av, &e)))
		return (-1);
	e.mlx_ptr = mlx_init();
	e.wdw_ptr = mlx_new_window(e.mlx_ptr, SIZE_L, SIZE_H, "Wolf3d");
	set_callbacks(&e);
	ft_logger(7, 2, L_INFO, "Starting main loop");
	mlx_loop(e.wdw_ptr);
	return (0);
}
