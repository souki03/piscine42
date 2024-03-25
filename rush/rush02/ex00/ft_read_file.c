/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:59:42 by rdupeux           #+#    #+#             */
/*   Updated: 2023/09/24 22:24:21 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_open(char *path)
{
	int	file_descriptor;

	file_descriptor = open(path, O_RDONLY);
	return (file_descriptor);
}

int	ft_get_size(int file_descriptor)
{
	int		size;
	char	byte;

	size = 0;
	while (read(file_descriptor, &byte, 1) == 1)
		size++;
	close(file_descriptor);
	return (size);
}

char	*ft_read(char *path)
{
	int		buf;
	char	*str;
	int		file_descriptor;

	file_descriptor = ft_open(path);
	buf = ft_get_size(file_descriptor);
	str = malloc(buf);
	file_descriptor = ft_open(path);
	if (file_descriptor == -1)
	{
		ft_print_error();
		return (NULL);
	}
	if (read(file_descriptor, str, buf) == -1)
	{
		ft_print_dict_error();
		free(str);
		return (NULL);
	}
	close(file_descriptor);
	return (str);
}

s_dict	*set_tab(char **tab)
{
	int		len;
	int		i;
	int		j;
	s_dict	*res;

	len = 0;
	j = 0;
	i = 0;
	while (tab[len])
		len++;
	res = malloc(len * sizeof(s_dict *));
	while (tab[i])
	{
		res[j].key = tab[i];
		i++;
		res[j].value = tab[i];
		i++;
		j++;
	}
	res[j].key = 0;
	free(tab);
	return (res);
}

s_dict	*get_dict(char *str)
{
	s_dict	*dict_base;
	s_dict	*dict_add;
	char	*res;

	dict_add = NULL;
	res = ft_read("numbers.dict");
	if (!res)
	{
		ft_print_error();
		return (NULL);
	}
	dict_base = set_tab(ft_dic_split(res));
	if (str)
	{
		free(res);
		res = ft_read(str);
		if (!res)
		{
			ft_print_error();
			return (NULL);
		}
		dict_add = set_tab(ft_dic_split(res));
	}
	free(res);
	return (merge_dict(dict_base, dict_add));
}

/* int main()
{
	s_dict *dict = get_dict(NULL);
	int i;

	i = 0;
	printf("%s\n", ft_read(ft_open("numbers.dict")));
	while (dict[i].key)
	{
		printf("key:%s\n", dict[i].key);
		printf("value:%s\n", dict[i].value);
		i++;
	}
	return (0);
} */
