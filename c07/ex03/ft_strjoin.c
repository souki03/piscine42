/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:27:44 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/25 17:55:11 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}

int	find_malloc_size(int size, char **strs, char *sep)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (size == 0)
		return (1);
	while (i < size)
	{
		res = res + ft_strlen(strs[i]);
		i++;
	}
	res = res + ft_strlen(sep) * (size - 1);
	return (res + 1);
}

char	*ft_strjoin( int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	i = 0;
	if (size == 0)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * find_malloc_size(size, strs, sep));
	if (!res)
		return (NULL);
	res[0] = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i != size - 1)
			ft_strcat(res, sep);
		i++;
	}
	res[ft_strlen(res)] = 0;
	return (res);
}

// #include <stdio.h>

// char *ft_strjoin(int size, char **strs, char *sep);

// int	main(int argc, char **argv)
// {
// 	//printf("./ex03/output___said___this___is___a___success :\n");
// 	printf("%s\n",  ft_strjoin(argc, argv, "___"));
// }