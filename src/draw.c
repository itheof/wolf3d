/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:44:22 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/09 21:54:14 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
static void	draw_line(t_env *e, t_ray ray)
{
	
}

void		draw(t_env *e)
{
	size_t			x;
	t_ray			ray;

	x = 0;
	SDL_RenderClear(e->sdl_buf);
	while (x < SIZE_L)
	{
		raycast(x, &ray, e);
		draw_line(e, ray);
		x++;
	}
	SDL_RenderPresent(e->sdl_buf);
}
