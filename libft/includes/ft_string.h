/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:03:23 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 16:04:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <string.h>

size_t		ft_strlen(const char *s);

int			ft_strcmp(const char *s1, const char *s2);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strdup(const char *s1);

void		replace(char *str, char target, char replace);

char		*ft_strcpy(char *dst, const char *src);

char		*ft_strcat(char *s1, const char *s2);

char		**ft_strsplit(char const *s, char c);

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isseparator(int c);

void		ft_bzero(void *v, size_t n);

#endif
