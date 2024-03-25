/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:33:04 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/13 13:55:06 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	z;

	i = 0;
	z = 0;
	while (dest[i])
		i++;
	while (src[z] && z < nb)
	{
		dest[i] = src[z];
		i++;
		z++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char c[] = "salut, ";
	char c2[] = "je suis trop beau non c faux";
	char size = 17;
	printf("%s\n", ft_strncat(c, c2, size));
	return 0;
}*/
