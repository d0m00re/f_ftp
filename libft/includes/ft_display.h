/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:05:05 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 16:05:31 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

# include <unistd.h>

void	ft_putchar(char c);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char const *s, int fd);

void	ft_putstr(char const *s);

void	ft_putstr_limit(char const *s, size_t size);

void	ft_putstr_fd_endl(char const *s, int fd);

void	ft_putstr_endl(char const *s);

void	ft_putnbr(int nb);
void	ft_putnbr_ui(unsigned int nb);

void	ft_putnbr_base(int nb, unsigned int base);
void	ft_putnbr_base_ui(unsigned int nb, unsigned int base);

#endif
