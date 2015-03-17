/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 09:19:15 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/17 16:58:49 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	**ft_superatoi(t_list *list)
{
	int		**tab;
	t_list	*old;
	int		i;
	int		j;

	tab = malloc(sizeof(*tab) * (ft_lstlen(list) + 1));
	j = 0;
	while (list)
	{
		old = list;
		list = list->next;
		tab[j] = malloc(sizeof(**tab) * (ft_tablen(old->content) + 1));
		i = 0;
		while (((void **)(old->content))[i])
		{
			tab[j][i] = ft_atoi(((void **)(old->content))[i]);
			i++;
		}
		tab[j++][i] = 0;
		ft_freetab(old->content);
		free(old);
	}
	tab[j] = 0;
	return (tab);
}

int		**ft_map(char *file)
{
	char	*str;
	int		fd;
	t_list	*list;

	str = NULL;
	list = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &str) == 1 && *str)
	{
		ft_lstpushback(&list, ft_lstnewcopy(ft_strsplit(str, ' '), 0));
		free(str);
	}
	if (fd > 0)
		free(str);
	close(fd);
	return (ft_superatoi(list));
}
