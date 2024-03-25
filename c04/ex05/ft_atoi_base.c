/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:37:51 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/23 07:09:58 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
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

int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	baselength;
	int	res;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	baselength = ft_strlen(base);
	if (!is_valid_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		if (index_in_base(str[i], base) == -1)
			return (0);
		res *= baselength;
		res += index_in_base(str[i], base);
		i++;
	}
	return (res * sign);
}

// #include <stdio.h>

// int	ft_atoi_base(char *str, char *base);

// int	main(void)
// {
// 	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
// 	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
// 	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
// 	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));

// }
