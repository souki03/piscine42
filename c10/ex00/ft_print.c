/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:33:13 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/23 04:09:56 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int nb)
{
	write(nb, &c, 1);
}

void	ft_putstr(char *str, int nb)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], nb);
		i++;
	}
}
