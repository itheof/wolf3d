/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:00:31 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/02 16:49:18 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# define BUFF_SIZE 1

# define C_EMERGENCY "\033[0;41;30m"
# define C_ALERT "\033[0;41;36m"
# define C_CRITICAL "\033[0;41;33m"
# define C_ERROR "\033[0;41;37m"
# define C_WARNING "\033[0;35m"
# define C_NOTICE "\033[0;33m"
# define C_INFO "\033[0;32m"
# define C_DEBUG "\033[0;34m"
# define C_REGULAR "\033[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_delim
{
	size_t			i;
	size_t			j;
}					t_delim;

enum
{
	L_EMERGENCY,
	L_ALERT,
	L_CRITICAL,
	L_ERROR,
	L_WARNING,
	L_NOTICE,
	L_INFO,
	L_DEBUG,
	L_REGULAR
};

typedef struct		s_buff
{
	char			*buff;
	int				offst;
	int				fd;
	int				readret;
	struct s_buff	*next;
}					t_buff;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2, int nb);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_whitespaces(char const *str);
char				*ft_itoa(int n);
void				ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putendlfree_fd(char *s, int fd);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnewcopy(void const *data, size_t data_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstpushback(t_list **list, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *lst);
void				**ft_lsttotab(t_list *list, int free);
int					**ft_strlsttoitab(t_list *lst, int destroy);
int					*ft_atabtoistr(char **tab);
int					ft_lstremove(t_list **list, t_list *elem, int i);

int					ft_freetab(void **tab);
size_t				ft_tablen(void **tab);
t_list				*ft_tabtolst(void **data);
void				**ft_tablineadd(void *line, void **tab);
void				**ft_tablinedel(void *line, void **tab);

int					get_next_line(int const fd, char **line);

void				ft_logger(int maxlvl, int fd, int loglvl, char *msg);
#endif
