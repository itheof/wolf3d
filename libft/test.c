/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 13:57:17 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/02 16:39:24 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int main()
{
	ft_logger(7, 2, L_DEBUG, "Ca, c est de la merde");
	sleep(3);
	ft_logger(7, 2, L_INFO, "Ca, ca peut etre utile");
	sleep(1);
	ft_logger(7, 2, L_NOTICE, "Ca commence a etre utile");
	sleep(1);
	ft_logger(7, 2, L_WARNING, "Ca, c est embetant");
	sleep(1);
	ft_logger(7, 2, L_ERROR, "Et merde....");
	sleep(1);
	ft_logger(7, 2, L_CRITICAL, "Au secours !!!");
	sleep(1);
	ft_logger(7, 2, L_ALERT, "La, il faudrait abort...");
	sleep(1);
	ft_logger(7, 2, L_EMERGENCY, "BAZOOKA !!!!!!");
	return (0);
}
