/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:02:43 by gsominsk          #+#    #+#             */
/*   Updated: 2017/02/17 14:33:30 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_LIBFT_H
# define H_LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
# include <stddef.h>

# define MIN(A, B) ((A < B) ? A : B)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *string1, const char *string2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *string1, const char *string2,
								size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_atoi(const char *string);
int					ft_isalpha(int character);
int					ft_isdigit(int character);
int					ft_isalnum(int character);
int					ft_isascii(int character);
int					ft_isprint(int character);
int					ft_toupper(int character);
int					ft_tolower(int character);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *str_b, const char *str_a, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *destination, const char *append,
					size_t n);
char				*ft_strcat(char *destination, const char *append);
char				*ft_strstr(const char *str_b, const char *str_a);
char				*ft_strrchr(const char *string, int symbol);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *string, int symbol);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strcpy(char *dst, const char *src);
char				**ft_strsplit(char const *s, char c);
char				*ft_strdup(const char *str);
char				*ft_strtrim(char const *s);
char				*ft_strnew(size_t size);
char				*ft_itoa(long long int n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memset(void *memptr, int value, size_t mem_len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_bzero(void *b, size_t length);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_putendl(char const *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putstr(char *str);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_putnbr(int n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
