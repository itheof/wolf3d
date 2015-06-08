/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:33:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/08 15:22:40 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	print_key(int keycode, t_env *e)
{
	char	buf[2048];
	char	*temp;

	ft_strcpy(buf, "Pressed key ");
	temp = ft_itoa(keycode);
	ft_strcat(buf, temp);
	free(temp);
	ft_logger(L_LVL, 2, L_DEBUG, buf);
}

int			expose_hook(void *param)
{
	draw(param);
}

int			key_hook(int keycode, void *param)
{
	t_env *e;

	e = param;
	print_key(keycode, e);
	if (keycode == 53)
		ft_exit(e);
	else if (keycode == 126)
		UP;
	else if (keycode == 123)
		LEFT;
	else if (keycode == 124)
		RIGHT;
	else if (keycode == 125)
		DOWN;
	return (0);
}

int			loop_hook(void *param)
{
	draw(param);
}
