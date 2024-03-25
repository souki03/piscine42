/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:07:38 by jeada-si          #+#    #+#             */
/*   Updated: 2023/09/17 15:04:28 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

/*Check that the string param is the right length
and a digit on even index or space on odd index.*/
int ft_check_param(char *str)
{
	int i;

	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	while (str[i] && i < 31)
	{
		if (str[i] < '0' || str[i] > '4')
			return (0);
		i = i + 2;
	}
	i = 1;
	while (str[i] && i < 31)
	{
		if (str[i] != ' ')
			return (0);
		i = i + 2;
	}
	return (1);
}

/*Return an int tab[16] of the parameters
same order as subject*/
int	ft_read_param(char *str, int tab[16])
{
	int	i;
	int	tabi;

	i = 0;
	tabi = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			tab[tabi] = str[i] - 48;
			tabi++;
		}
		i++;
	}
	return (1);
}
// 
// int main(int argc, char **argv)
// {
// 	int tab[16];
// 	int i;
// 
// 	i = 0;
// 	if (argc == 2 && ft_read_param(argv[1], tab))
// 	{
// 		;
// 		while (i < 16)
// 		{
// 		printf("INT : %d\n", tab[i]);
// 		i++;
// 		}
// 	}
// 
// 	if(argc)
// 		printf("%d",ft_check_param(argv[1]));
// 
// }
