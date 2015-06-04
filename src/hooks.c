/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:33:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/04 16:43:57 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	expose_hook(void *param)
{
	draw(param);
}

void	key_hook(int keycode, void *param)
{
	t_env *e;

	
	e = param;
	draw(e);
}

void	loop_hook(void *param)
{
	draw(param);
}
