/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:02:49 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/22 15:55:29 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
int				ft_strlen(const char *s);
void			*ft_memset(void *str, int c, size_t len);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void	*dst, const void *src, unsigned long n);
void			*ft_memmove(void *dst, const void *src, unsigned long len);
unsigned long	ft_strlcpy(char *dst, const char *src, size_t dstsize);
unsigned long	ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *str1, const char *str2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strnstr(const char *hstack, const char *needle, size_t len);
long			ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *str1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));
char			*get_next_line(int fd, char *line, int i);
char			*fill_line_buffer(int fd, char *stock, char *buffer);
int				ft_strchr_line(const char *line, int c);
char			*ft_substr_l(char const *s, unsigned int start, \
				size_t len, size_t i);
char			*free_str(char *str);
char			*ft_strjoin_l(char *s1, char const *s2);
char			*init(char *stock, int fd);
int				ft_printf(const char *str, ...);
int				va_arg_c(va_list args);
int				va_arg_di(va_list args);
int				va_arg_prce(void);
int				va_arg_p(va_list args);
int				va_arg_s(va_list args);
int				va_arg_u(va_list args);
int				va_arg_x(va_list args, char c);
int				ft_count_hexa(unsigned long hexa);
int				ft_count_digit(int n);
int				ft_putstr(char *str);
void			ft_num_str(char *str, int len, unsigned int number);
void			ft_p_hexa_str(char *str, int len, unsigned long n, int temp);
void			ft_x_hexa_str(char *str, int len, unsigned long n, char format);
int				ft_count_u_digit(unsigned int n);

#endif