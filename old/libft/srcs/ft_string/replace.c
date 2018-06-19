/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:13:39 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:16:39 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  replace char by another | all string
*/

void		replace(char *str, char target, char replace)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == target)
			str[i] = replace;
		i++;
	}
}
