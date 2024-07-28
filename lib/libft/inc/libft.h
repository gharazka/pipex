/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:22:09 by gharazka          #+#    #+#             */
/*   Updated: 2023/10/28 20:24:53 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>
# define BUFFER_SIZE 10

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *c, int fd);
void	ft_putendl_fd(char *c, int fd);
int		ft_putnbr_fd(int nb, int fd, int len);
int		ft_putunbr_fd(unsigned int nb, int fd, int len);
int		ft_puthex_fd(unsigned long long int n, unsigned long int temp, int len);
int		ft_putcaphex_fd(unsigned int n, int temp, int len);
int		ft_putmemory_fd(unsigned long long int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memset(void *s, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2, int free_s1);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_findchar(const char *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
