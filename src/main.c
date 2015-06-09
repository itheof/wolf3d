/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:46:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/09 21:55:20 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_sdl(t_env *e)
{
	char	lbuf[2048];

	*lbuf = 0;
	ft_logger(L_LVL, 2, L_INFO, "Initializing SDL....");
	e->sdl_wdw = NULL;
	e->sdl_buf = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_strcpy(lbuf, "SDL could not initialize: ");
		ft_strcat(lbuf, SDL_GetError());
		ft_logger(7, 2, L_EMERGENCY, lbuf);
		ft_exit(e);
	}
	else
	{
		if (!(e->sdl_wdw = SDL_CreateWindow( "Wolf3d", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SIZE_L, SIZE_H, SDL_WINDOW_SHOWN)))
		{
			ft_strcpy(lbuf, "Can't create window:");
			ft_strcat(lbuf, SDL_GetError());
			ft_logger(7, 2, L_EMERGENCY, lbuf);
			ft_exit(e);
		}
	}
	ft_logger(L_LVL, 2, L_INFO, "SDL set successfully !");
}

static void	ft_rulekeys(t_env *e, SDL_Event ev)
{
	if (ev.type == SDL_KEYUP)
	{
		if (KEY == SDLK_DOWN)
			e->kb[DOWN] = 0;
		else if (KEY == SDLK_UP)
			e->kb[UP] = 0;
		else if (KEY == SDLK_LEFT)
			e->kb[LEFT] = 0;
		else if (KEY == SDLK_RIGHT)
			e->kb[RIGHT] = 0;
	}
	else if (ev.type == SDL_KEYDOWN)
	{
		if (KEY == SDLK_DOWN && !e->kb[UP])
			e->kb[DOWN] = 1;
		else if (KEY == SDLK_UP && !e->kb[DOWN])
			e->kb[UP] = 1;
		else if (KEY == SDLK_LEFT && !e->kb[RIGHT])
			e->kb[LEFT] = 1;
		else if (KEY == SDLK_RIGHT && !e->kb[LEFT])
			e->kb[RIGHT] = 1;
	}
}

int			main(int ac, char **av)
{
	t_env		e;
	SDL_Event	ev;

	ft_logger(7, 2, L_INFO, "Initializing...");
	set_env(&e, ac, av);
	if (!(e.levels = load_levels(*av, &e)))
		return (-1);
	init_sdl(&e);
	e.sdl_buf = SDL_CreateRenderer(e.sdl_wdw, -1, SDL_RENDERER_ACCELERATED);
	ft_logger(7, 2, L_INFO, "Starting main loop");
	while (42)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT || (ev.type == SDL_KEYUP &&
						KEY == SDLK_ESCAPE))
				ft_exit(&e);
			if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
				ft_rulekeys(&e, ev);
			ft_move(&e);
			draw(&e);
		}
		draw(&e);
	}
	return (0);
}
