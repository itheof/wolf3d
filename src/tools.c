/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:50:14 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/08 15:12:18 by tvallee          ###   ########.fr       */
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
	return (current->content);
}
