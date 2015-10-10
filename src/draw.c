/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:44:22 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/13 14:11:02 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_line(t_env *e, t_ray ray)
{
	SDL_Point	*line;
	int			i;

	SDL_SetRenderDrawColor(e->sdl_buf, ray.color / 0x010000 * ray.fog,
			ray.color % 0x010000 * ray.fog
			/ 0x000100, ray.color % 0x000100 * ray.fog, 0xFF);
	i = 0;
	line = malloc(sizeof(*line) * (ray.draw_end - ray.draw_start + 1));
	while (ray.draw_start + i <= ray.draw_end)
	{
		line[i].x = ray.x;
		line[i].y = ray.draw_start + i;
		i++;
	}
	SDL_RenderDrawPoints(e->sdl_buf, line, ray.draw_end - ray.draw_start +
			1);
	free(line);
}

void		draw(t_env *e)
{
	size_t			x;
	t_ray			ray;
	SDL_Rect		background;

	x = 0;
	SDL_RenderClear(e->sdl_buf);
	SDL_SetRenderDrawColor(e->sdl_buf, 0x80, 0x80, 0x80, 0xFF);
	background.x = 0;
	background.y = 0;
	background.w = SIZE_L;
	background.h = SIZE_H / 2;
	SDL_RenderFillRect(e->sdl_buf, &background);
	SDL_SetRenderDrawColor(e->sdl_buf, 0x66, 0x33, 0x00, 0xFF);
	background.x = 0;
	background.y = SIZE_H / 2;
	background.w = SIZE_L;
	background.h = SIZE_H;
	SDL_RenderFillRect(e->sdl_buf, &background);
	while (x < SIZE_L)
	{
		raycast(x, &ray, e);
		draw_line(e, ray);
		x++;
	}
	SDL_RenderPresent(e->sdl_buf);
}
