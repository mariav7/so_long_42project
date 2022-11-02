/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:50:29 by mflores-          #+#    #+#             */
/*   Updated: 2022/09/13 13:14:10 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// General
# include <unistd.h>
# include <stdlib.h>

// LIBFT
# include <string.h>
# include <stdio.h>

// FT_PRINTF
# include <stdarg.h>

// GNL
# include <fcntl.h>

// Prototypes LIBFT
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(char c);
int		ft_tolower(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Prototypes FT_PRINTF
# define BASE_DEC "0123456789"
# define HEXA_MIN "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"
# define NIL_PTR "(nil)"
# define CONV "cspdiuxX%"

int		ft_printf(const char *format, ...);
int		ft_print_arg(const char *format, int i, va_list args);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int nbr);
int		ft_printbase_u(unsigned int nbr, int base, const char *hexa);
int		ft_printptr_u(unsigned long nbr, int base, const char *hexa);
int		ft_putptr_u(unsigned long nbr, int base, const char *hexa);

// Prototypes GNL
// Redefine buffer_size if needed with flag -D BUFFER_SIZE=nbr_you_want
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

char	*get_next_line(int fd);
char	*gnl_read_file(int fd, char *stash);
char	*gnl_get_line(char *stash);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_free(char *stash, char *buff);
char	*gnl_strjoin(char *stash, char *buffer);
char	*gnl_update_stash(char *old_stash);

#endif
