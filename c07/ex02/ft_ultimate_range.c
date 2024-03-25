/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:27:37 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/22 01:26:53 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlen(int *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(int) * (max - min));
	if (min >= max)
	{
		ret = NULL;
		return (0);
	}
	if (!ret)
		return (-1);
	while (min < max)
	{
		ret[i] = min;
		i++;
		min++;
	}
	*range = ret;
	return (i);
}
