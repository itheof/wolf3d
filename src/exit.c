/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 11:37:54 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/13 14:21:40 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_free_levels(t_list *current)
{
	t_list	*next;

	while (current)
	{
		next = current->next;
		ft_freetab((void **)current->content);
		free(current);
		current = next;
	}
}

void		ft_exit(t_env *e)
{
	ft_logger(L_LVL, 2, L_INFO, "Exiting...");
	ft_free_levels(e->levels);
	ft_logger(L_LVL, 2, L_DEBUG, "Freed levels.");
	SDL_DestroyRenderer(e->sdl_buf);
	ft_logger(L_LVL, 2, L_DEBUG, "Destroyed renderer");
	SDL_DestroyWindow(e->sdl_wdw);
	ft_logger(L_LVL, 2, L_DEBUG, "Destroyed window");
	ft_logger(L_LVL, 2, L_NOTICE, "Bye ! =)");
	exit(0);
}
