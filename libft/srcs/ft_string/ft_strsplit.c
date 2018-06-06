/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:13:06 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 23:05:50 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_nb_word(const char *str, char sep)
{
	int			nb_word;
	int			count;
	int			begin;

	nb_word = 0;
	count = 0;
	begin = 0;
	while (str && str[count])
	{
		if (begin == 0 && str[count] != sep)
		{
			nb_word++;
			begin = 1;
		}
		if (begin == 1 && str[count] == sep)
			begin = 0;
		count++;
	}
	return (nb_word);
}

static char		*extract_word_with_sep(char const *s, char sep, int *cursor)
{
	int			size;
	int			count;
	char		*str;

	count = 0;
	size = 0;
	while (s[(*cursor)] == sep)
		(*cursor)++;
	while (s[(*cursor) + size] && s[(*cursor) + size] != sep)
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	while (count < size)
	{
		str[count] = s[(*cursor) + count];
		count++;
	}
	(*cursor) += count;
	str[count] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			nb_word;
	int			count;
	int			cursor;

	count = 0;
	cursor = 0;
	nb_word = ft_nb_word(s, c);
	str = malloc(sizeof(char *) * (nb_word + 1));
	if (!str)
		return (0);
	while (count < nb_word)
	{
		str[count] = (char *)extract_word_with_sep(s, c, &cursor);
		count++;
	}
	str[count] = 0;
	if (nb_word == 0)
		str[0] = 0;
	return ((char **)str);
}

char			**ft_strsplit_nb_word(char const *s, char c, int *size)
{
	char		**str;
	int			nb_word;
	int			count;
	int			cursor;

	count = 0;
	cursor = 0;
	nb_word = ft_nb_word(s, c);
	*size = nb_word;
	str = malloc(sizeof(char *) * (nb_word + 1));
	if (!str)
		return (0);
	while (count < nb_word)
	{
		str[count] = (char *)extract_word_with_sep(s, c, &cursor);
		count++;
	}
	str[count] = 0;
	if (nb_word == 0)
		str[0] = 0;
	return ((char **)str);
}

void			*ft_strsplit_free(char **sp)
{
	int			c;

	c = 0;
	if (!sp)
		return (0);
	while (sp[c])
	{
		free(sp[c]);
		c++;
	}
	free(sp);
	sp = 0;
	return (0);
}
