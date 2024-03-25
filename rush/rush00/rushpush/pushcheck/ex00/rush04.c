/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 00:24:42 by souki             #+#    #+#             */
/*   Updated: 2023/09/10 17:29:50 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> // Pour INT_MAX

void	ft_putchar(char c);

void	line_up(int x)
{
	int	b_up;

	b_up = x - 2;
	ft_putchar('A');
	while (b_up > 0)
	{
		ft_putchar('B');
		b_up--;
	}
	if (x >= 2)
		ft_putchar('C');
}

void	line_down(int x)
{
	int	b_down;

	b_down = x - 2;
	if (x >= 1)
		ft_putchar('C');
	while (b_down > 0)
	{
		ft_putchar('B');
		b_down--;
	}
	if (x >= 2)
		ft_putchar('A');
}

void	lines_middle(int x, int y)
{
	int	x_value;

	x_value = x;
	while (y > 2)
	{
		ft_putchar('B');
		y--;
		while (x > 2)
		{
			ft_putchar(' ');
			x--;
		}
		if (x_value > 2)
			ft_putchar('B');
		x = x_value;
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0 || x > INT_MAX || y > INT_MAX)
		return ;
	else
	{
		line_up(x);
		ft_putchar('\n');
		lines_middle(x, y);
		if (y >= 2)
			line_down(x);
		if (x > 1)
			ft_putchar('\n');
	}
}
