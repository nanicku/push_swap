/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:01:51 by mshad             #+#    #+#             */
/*   Updated: 2021/10/08 15:01:52 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);

#endif