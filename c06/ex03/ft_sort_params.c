/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:48:21 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/21 16:49:57 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] == str2[i]) && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_strswap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

int	main(int argsc, char **argsv)
{
	int	i;
	int	o;

	i = 1;
	while (argsv[i])
	{
		o = i + 1;
		while (o < argsc)
		{
			if (ft_strcmp(argsv[i], argsv[o]) > 0)
				ft_strswap(&argsv[i], &argsv[o]);
			o++;
		}
		i++;
	}
	i = 1;
	while (i < argsc)
	{
		ft_putstr(argsv[i]);
		ft_putchar('\n');
		i++;
	}
}
