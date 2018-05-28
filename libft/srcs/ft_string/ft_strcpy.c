/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:12:25 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:12:35 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcpy(char *dst, const char *src)
{
	int		count;

	count = 0;
	while (*src)
	{
		dst[count] = *src;
		src++;
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
