/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:06:22 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/10 12:37:17 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <aio.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

/*
Notes:
-    if a function is supposed to set a pntr, pass a **
*/
enum e_types
{
	nil,
	i32,
	f32,
	f64,
	pntr,
	other_type
};

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

double	ft_atod_s(char *str, int *error);
double	ft_atod(char *str);
float	ft_atof_s(char *str, int *error);
float	ft_atof(char *str);
int		ft_atoi(const char *nptr);
int		ft_atoi_s(const char *nptr, int *err);

void	*ft_calloc(size_t nmeb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char *s2, int free1, int free2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s1, char c);
void	ft_free_splitted(char **split_output);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Returns:
//	-1 for errors, 0 for key not found, 1 for success
//	On success with t as pntr, 
//  the pointer to the duplicated string will be set to value
//	So passing a pointer to a pointer is intended behaviour
//
//	Errors only apply for ascii to data type conversion and invalid input values
int		ft_set_key(char **argv, char *searched_k, void *value, enum e_types t);
int		ft_key_value(char *str, char **key, char **value, int free_str);
int		ft_set_void(void *to_write, char *value, enum e_types out_type);

// Returns: parameter condition
int		ft_free(void **pntr, int condition);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

# ifdef TEST

//int		main(int argc, char *argv[]);

# endif
#endif
