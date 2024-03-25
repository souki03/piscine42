/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_line_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:06:12 by jeada-si          #+#    #+#             */
/*   Updated: 2023/09/20 12:22:05 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_rev(int view[4]);
/*Returns 1 if a given view is valid for a given view value, 0 otherwise
int	ft_is_view_valid(int tab[4], int view_value)
{
	int	i;
	int	count;
	int	j;
	int	higher;

	count = 1;
	i = 1;
	while(i < 4)
	{
		j = 0;
		higher = 1;
		while (j < i && higher)
		{
			if (tab[i] < tab[j])
				higher = 0;
			j++;
		}
		if(higher)
			count += 1;

	i++;
	}
	return (count == view_value);
}
*/

/*Counts the visble skycrapers in one way or reverse.*/
int	ft_count_skycrapers(int tab[4], int reverse)
{
	int	i;
	int	count;
	int	highest;
	int	index;

	count = 0;
	highest = 0;
	i = 0;
	while (i < 4)
	{
		index = i;
		if (reverse)
			index = 3 - i;
		if (tab[index] > highest)
		{
			count++;
			highest = tab[index];
		}			
		i++;
	}
	return (count);
}

/*Checks that there is no doublon in tab.*/
int	ft_check_unicity(int tab[4])
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] && i < 4)
	{
		j = 0;
		while (tab[j] && j < 4)
		{
			if (i != j && tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*Check that if one of view_value is 4, line is 1 2 3 4 ignoring 0*/
int	ft_check_value_max(int tab[4], int view_value_1, int view_value_2)
{
	int	i;

	if (view_value_1 == 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab[i] && tab[i] != i + 1)
				return (0);
			i++;
		}
	}
	if (view_value_2 == 4)
	{
		i = 3;
		while (i > -1)
		{
			if (tab[i] && tab[i] != 4 - i)
				return (0);
			i--;
		}
	}
	return (1);
}

/*Checks that line is valid so far*/
int	ft_is_line_valid(int tab[4], int view_value_1, int view_value_2, int index)
{
	int	count;
	int	count_rev;

	if (view_value_1 == 1 && tab[0] && tab[0] != 4)
		return (0);
	if (!ft_check_unicity(tab))
		return (0);
	if (!ft_check_value_max(tab, view_value_1, view_value_2))
		return (0);
	count = ft_count_skycrapers(tab, 0);
	if (count > view_value_1)
		return (0);
	count_rev = ft_count_skycrapers(tab, 1);
	if (index == 3 && count != view_value_1)
		return (0);
	if (index == 3 && count_rev != view_value_2)
		return (0);
	return (1);
}
// 
// int	main(void)
// {
// 	int	tab[4] = {1, 2, 3, 4};
// 	printf("Tab : %d %d %d %d \n", tab[0], tab[1], tab[2], tab[3]);
// 	printf("%d\n", ft_is_line_valid_so_far(tab, 1, 4));
// 	return 0;
// }
