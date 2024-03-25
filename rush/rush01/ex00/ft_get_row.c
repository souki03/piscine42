/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:05:02 by jeada-si          #+#    #+#             */
/*   Updated: 2023/09/17 12:20:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_get_col(int tab[4][4], int col[4], int c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		col[i] = tab[i][c];
		i++;
	}
	return (col);
}

int	*ft_get_row(int tab[4][4], int row[4], int r)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		row[i] = tab[r][i];
		i++;
	}
	return (row);
}
/*
void	ft_print(int tab[4][4]);

int main(void)
{
	int tab[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6 , 7}};
	int col[4];

	ft_print(tab);
	ft_get_col(tab, col, 2);

	printf("\n%d %d %d %d", col[0], col[1], col[2], col[3]);
}
*/