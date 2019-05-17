/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:19:29 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 20:15:47 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}					t_list;

typedef struct		s_dcl
{
	char									c;
	int										n;
	void									*data;

	struct s_dcl							*next;
	struct s_dcl							*previous;
}					t_dcl;

typedef struct		s_matrix
{
	int			rowc;
	int			colc;
	int			is_square;
	int			is_diagonal;
	int			max_value;

	int			**table;
}					t_matrix;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);

void				*ft_memset(void *str, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);

char				*ft_strdup(const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strcpy(char *dst, const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *str, const char *sub, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_putstr_fd(char const *s, int fd);

int					ft_isspace(char c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
void				ft_putchar_fd(char c, int fd);
int					is_left_orient(char c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstfreeone(t_list **alst);
void				ft_lstfree(t_list **alst);
t_list				*ft_lstnew_unsafe(void const *content, size_t content_size);

int					ft_check_brackets(char *str);
int					ft_isoperand(char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);

int					ft_atoi(const char *str);

void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_nputchar(int n, char c);

int					dcl_rpn(t_dcl *elem);
void				dcl_el_printer(t_dcl *elem);
void				dcl_printer(t_dcl *elem);
void				dcl_begin(t_dcl **elem);
void				dcl_back(t_dcl **elem);
void				dcl_end(t_dcl **elem);
void				dcl_forward(t_dcl **elem);
t_dcl				*dcl_creator(char c, int n);
void				dcl_push_back(t_dcl **first, t_dcl *next);
t_dcl				*make_rpn(char *str);
void				dcl_el_printer(t_dcl *elem);
void				dcl_printer(t_dcl *elem);
void				dcl_printer_back(t_dcl *elem);
t_dcl				*dcl_creator(char c, int n);
void				dcl_push_back(t_dcl **first, t_dcl *next);
int					dcl_len(t_dcl *elem);
void				dcl_back(t_dcl **elem);
void				dcl_begin(t_dcl **elem);
void				dcl_forward(t_dcl **elem);
void				dcl_end(t_dcl **elem);
void				dcl_take_n(int n, t_dcl **elem);

int					calc(char *expr);

t_matrix			*make_matrix(int rowc, int colc, int *arr, int n);
void				print_matrix(t_matrix *matrix);
t_matrix			*add_matrix(t_matrix *left, t_matrix *right);

#endif
