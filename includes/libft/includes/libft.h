/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:12:52 by wiferrei          #+#    #+#             */
/*   Updated: 2024/03/27 16:07:34 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);

int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					find_char_index(char *str, char c);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

size_t				ft_strlen(const char *str);
size_t				ft_strlen_nl(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *sn1, const char *sn2, size_t nb);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *cmp);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strremove(char *str, char *chars);
// void				ft_error_handler(char *message);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_calloc_memory(size_t count, size_t size);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char				*ft_strdup(char *src);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strndup(const char *s, size_t n);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char				*ft_search_and_replace_all(const char *str,
						const char *srch, const char *rplc);
char				*ft_search_and_replace_first(const char *str,
						const char *srch, const char *rplc);
char				*ft_strtok(char *str, const char *delim);

// ft_printf

int					ft_printf(const char *str, ...);
void				ft_types(char *str, va_list args, int i,
						long int *chr_total);
void				ft_putchar(char c, long int *chr_total);
void				ft_puthexa(unsigned int nbr, long int *chr_total,
						int uporlow);
void				ft_putadd(unsigned long int nbr, long int *chr_total,
						int x);
void				ft_putnbr(int nbr, long int *chr_total);
void				ft_putstr(char *str, long int *chr_total);
void				ft_unsgint(unsigned int nbr, long int *chr_total);

// Free functions
void				ft_free_str_array(char **str);

#endif