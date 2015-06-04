/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_levels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:57:47 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/04 16:28:48 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		*parse_line(t_list **list)
{
	t_list	*temp;
	int		*line;
	int		i;

	i = 0;
	temp = *list;
	line = malloc(sizeof(int) * (1 + ft_tablen(temp->content)));
	while (((char **)(temp->content))[i])
	{
		line[i] = ft_atoi(((char **)(temp->content))[i]);
		i++;
	}
	line[i] = 0;
	ft_freetab((void **)(temp->content));
	*list = temp->next;
	free(temp);
	return (line);
}

static int		**to_i_tab(int fd, t_env *e)
{
	t_list	*list;
	char	*str;
	int		**tab;
	int		i;

	list = NULL;
	while (get_next_line(fd, &str) == 1)
	{
		ft_lstpushback(&list, ft_lstnewcopy(ft_strsplit(str, ' '), 0));
		free(str);
	}
	free(str);
	i = 0;
	tab = malloc(sizeof(*tab) * (ft_lstlen(list) + 1));
	while (list)
		tab[i++] = parse_line(&list);
	tab[i] = NULL;
	close(fd);
	return (tab);
}

static t_list	*ft_parse_level(t_fil *file, char *path, t_env *e)
{
	char	log_buf[1024];
	char	f_path[2048];
	t_list	*ret;
	int		fd;

	ret = NULL;
	if (file->d_name[0] != '.')
	{
		ft_strcpy(f_path, path);
		ft_strcat(f_path, "/");
		ft_strcat(f_path, file->d_name);
		ft_strcpy(log_buf, "Loading level: ");
		ft_strcat(log_buf, f_path);
		ft_logger(L_LVL, 2, L_DEBUG, log_buf);
		ret = ft_memalloc(sizeof(*ret));
		ft_strcpy(log_buf, "Can't open level: ");
		ft_strcat(log_buf, f_path);
		if ((fd = open(f_path, O_RDONLY)) < 0)
		{
			ft_logger(L_LVL, 2, L_WARNING, log_buf);
			free(ret);
		}
		else
			ret->content = to_i_tab(fd, e);
	}
	return (ret);
}

t_list		*load_levels(char *av, t_env *e)
{
	t_list	*list;
	DIR		*dir;
	char	path[2048];
	t_fil	*file;

	*path = 0;
	ft_strncpy(path, av, ft_strrchr(av, '/') - av);
	path[ft_strrchr(av, '/') - av] = 0;
	ft_strcat(path, "/levels");
	list = NULL;
	ft_logger(L_LVL, 2, L_INFO, "Loading Levels...");
	dir = opendir(path);
	while (dir && (file = readdir(dir)))
		ft_lstpushback(&list, ft_parse_level(file, path, e));
	if (dir && list)
		closedir(dir);
	else
		ft_logger(L_LVL, 2, L_EMERGENCY, "No levels loaded. Aborting");
}
