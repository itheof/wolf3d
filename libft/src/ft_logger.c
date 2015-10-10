/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 12:12:10 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/10 00:06:05 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_time(int fd)
{
	time_t		st;

	st = time(NULL);
	st = st % 86400;
	ft_putstr_fd(C_INFO, fd);
	ft_putstr_fd("[", fd);
	if (st / 3600 < 10)
		ft_putchar('0');
	ft_putnbr_fd(st / 3600, fd);
	ft_putstr_fd(":", fd);
	if ((st % 3600) / 60 < 10)
		ft_putchar('0');
	ft_putnbr_fd((st % 3600) / 60, fd);
	ft_putstr_fd(":", fd);
	if ((st % 3600) % 60 < 10)
		ft_putchar('0');
	ft_putnbr_fd((st % 3600) % 60, fd);
	ft_putstr_fd("]", fd);
	ft_putstr_fd(C_REGULAR, fd);
	ft_putstr_fd(" ", fd);
}

static void	ft_print_type(int loglvl, int fd)
{
	if (loglvl == L_EMERGENCY)
		ft_putstr_fd("[FATAL]    ", fd);
	else if (loglvl == L_ALERT)
		ft_putstr_fd("[ALERT]    ", fd);
	else if (loglvl == L_CRITICAL)
		ft_putstr_fd("[CRITICAL] ", fd);
	else if (loglvl == L_ERROR)
		ft_putstr_fd("[ERROR]    ", fd);
	else if (loglvl == L_WARNING)
		ft_putstr_fd("[WARNING]  ", fd);
	else if (loglvl == L_NOTICE)
		ft_putstr_fd("[NOTICE]   ", fd);
	else if (loglvl == L_INFO)
		ft_putstr_fd("[INFO]     ", fd);
	else if (loglvl == L_DEBUG)
		ft_putstr_fd("[DEBUG]    ", fd);
}

void		ft_logger(int maxlvl, int fd, int loglvl, char *msg)
{
	char	*color[9];

	color[L_EMERGENCY] = C_EMERGENCY;
	color[L_ALERT] = C_ALERT;
	color[L_CRITICAL] = C_CRITICAL;
	color[L_ERROR] = C_ERROR;
	color[L_WARNING] = C_WARNING;
	color[L_NOTICE] = C_NOTICE;
	color[L_INFO] = C_INFO;
	color[L_DEBUG] = C_DEBUG;
	color[L_REGULAR] = C_REGULAR;
	if (maxlvl < loglvl)
		return ;
	print_time(fd);
	ft_putstr_fd(color[loglvl], fd);
	ft_print_type(loglvl, fd);
	ft_putstr_fd(msg, fd);
	ft_putendl_fd(C_REGULAR, fd);
}
