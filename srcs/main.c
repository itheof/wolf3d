/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:21:35 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/17 16:16:07 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"



int		expose_hook(t_env *e)
{
	draw(e);
}

int		key_hook(int keycode, t_env *e)
{
	draw(e);
}

int		main()
{
	t_env	e;

	e.map = ft_map("../map.w3d");
	e.mlxptr = mlx_init();
	e.win = mlx_new_window(e.mlxptr, WIDTH, HEIGHT, "wolf3D");
	mlx_key_hook(e.window, key_hook, &e);
	mlx_expose_hook(e.window, draw, &e);
	draw(&e);
	mlx_loop(e.mlxptr);
	return (0);
}
