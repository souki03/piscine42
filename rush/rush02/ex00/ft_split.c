/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:05:55 by ftilliet          #+#    #+#             */
/*   Updated: 2023/09/24 23:11:09 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int	is_sep(char c, char *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

void	write_dic_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (is_sep(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_dic_split(char **tab, char *str)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		else
		{
		j = 0;
			while (str[i+j] != ' ')
				j++;
			tab[word] = malloc(sizeof(char) * (j + 1));
			write_dic_word(tab[word], str + i, " :");
			i += j;
			word++;
			while (str[i] == ' ')
				i++;
			j = 0;
			while (str[i + j] != '\n' && str[i + j])
				j++;
			tab[word] = malloc(sizeof(char) * (j + 1));
			write_dic_word(tab[word], str + i, "\n");
			i += j;
			word++;
		}
	}
}

int	count_dic_words(char *str)
{
	int		i;
	int		word_count;

	word_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			i++;
		else
		{
			while (str[i] != ':' && str[i])
				i++;
			word_count++;
			while (str[i] == ' ')
				i++;
			while (str[i] != '\n' && str[i])
				i++;
			word_count++;
		}
	}
	return (word_count);
}

char	**ft_dic_split(char *str)
{
	char	**res;
	int		words;

	words = count_dic_words(str);
	res = malloc(sizeof(char *) * (words + 1));
	res[words] = 0;
	write_dic_split(res, str);
	return (res);
}