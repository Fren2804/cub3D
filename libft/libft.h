/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:21:28 by mvassall          #+#    #+#             */
/*   Updated: 2025/07/25 16:58:04 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdarg.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isspace(int c);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *str);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

int			ft_atoi(const char *str);
long int	ft_atol(const char *str);
void		ft_bzero(void *s, size_t n);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
void		*ft_dispose_split(char **fields);
int			ft_split_count(char **fields);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new_node);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_node);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstclean(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_FD 256
/*
typedef struct s_tlist
{
	char			buf[BUFFER_SIZE];
	ssize_t			count;
	struct s_tlist	*next;
}	t_tlist;

char		*get_next_line(int fd);
char		*gnl_get_line_array(t_tlist *frags);
t_tlist		*gnl_get_last_frag(t_tlist *frags);
ssize_t		gnl_fragchr(t_tlist *frag, char c);
char		*gnl_memmove(char *dst, const char *src, size_t n);
*/

// ft_printf
# define MAX_DIGITS 32

int			ft_dprintf(int fd, const char *fmt, ...);
int			ft_printf(const char *fmt, ...);
int			ft_c_conversion(int fd, int c);
int			ft_s_conversion(int fd, char *str);
int			ft_d_conversion(int fd, int n);
int			ft_u_conversion(int fd, unsigned int n);
int			ft_p_conversion(int fd, void *ptr);
int			ft_x_conversion(int fd, unsigned long n, int is_uppercase);

typedef struct s_buf
{
	char			*buf;
	char			*start;
	unsigned int	buffer_size;
	int				ungetc;
}	t_buf;

char		*gnl_getline(int fd, t_buf *rb);
t_buf		*gnl_alloc_buf(unsigned int buffer_size);
void		*gnl_dispose(t_buf *sb);
size_t		gnl_strlen(char *str);
char		*get_next_line(int fd);
ssize_t		gnl_read_buf(int fd, t_buf *rb);
int			gnl_getchar(int fd, t_buf *rb);
int			gnl_ungetchar(int c, t_buf *rb);
char		*ft_append_char(char *dst, char c);
char		*ft_append_string(char *dst, char *str);

int			ptr_array_len(void **ptrarray);
void		**ptr_array_append(void **ptrarray, void *ptr);
void		ptr_array_freeall(void **ptrarray);

int			ft_is_int(char *str);
uint64_t	ft_get_time_us(void);
#endif
