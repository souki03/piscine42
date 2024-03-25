/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:34:45 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/12 19:50:13 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*passenmini(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *src)
{
	int	i;

	i = 0;
	passenmini(src);
	while (src[i])
	{
		if (src[i] == '-' || src[i] == '+' || src[i] == 32)
			if (src[i + 1] >= 'a' && src[i + 1] <= 'z')
			src[i + 1] = src[i + 1] - 32;
		i++;
	}
	src[0] = src[0] - 32;
	return (src);
}
/*
int	main(void)
{
	char c[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s", ft_strcapitalize(c));
	return 0;
}*/
