/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:57:02 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/23 06:32:51 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verif(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= ' '
				|| base[i] > 126 || base[j] <= ' ' || base[j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (verif(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr != 0)
		{
			if (nbr / ft_strlen(base) != 0)
				ft_putnbr_base(nbr / ft_strlen(base), base);
			ft_putchar(base[nbr % ft_strlen(base)]);
		}
	}
}

// #include <unistd.h>

// void	ft_putnbr_base(int nbr, char *base);

// int		main(void)
// {
// 	write(1, "42:", 3);
// 	ft_putnbr_base(42, "0123456789");
// 	write(1, "\n2a:", 4);
// 	ft_putnbr_base(42, "0123456789abcdef");
// 	write(1, "\n-2a:", 5);
// 	ft_putnbr_base(-42, "0123456789abcdef");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "0");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "+-0123456789abcdef");
// 	write(1, "\n:", 2);
// 	ft_putnbr_base(42, "\t0123456789abcdef");
// }