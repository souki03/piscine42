/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:09:13 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/21 01:56:29 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (to_find[y] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + y] == to_find[y] && str[i + y] != '\0')
		{
			y++;
		}
		if (to_find[y] == '\0')
		{	
			return (str + i);
		}
		i++;
		y = 0;
	}
	return (0);
}
/*
int	main(void)
{
	char c[] = "Je suis dans un avion rouge";
	char c2[] = "avion";
	printf("%s\n", ft_strstr(c, c2));
	return 0;
}*/
