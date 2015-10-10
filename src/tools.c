/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:50:14 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/12 19:25:17 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		**seek_lvl(t_env *e)
{
	t_list	*current;
	size_t	i;

	i = e->current_lvl;
	current = e->levels;
	while (i--)
		current = current->next;
	if (current && current->content)
		return (current->content);
	else
		return (NULL);
}

int		can_move(int n, t_env *e)
{
	if (n == 9)
		return (1);
	else if (n == 6)
	{
		ft_spawn(e, e->current_lvl + 1);
		return (0);
	}
	else
		return (0);
}
