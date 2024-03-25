/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:36:40 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/23 07:48:30 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

void	ft_putstr(char *str, int nb);

int	main(int argc, char **argv)
{
	FILE	*fichier;
	char	ligne[256];

	fichier = (open(argv[1], "r"));
	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("File name missing.\n", 2);
		if (argc > 2)
			ft_putstr("Too many arguments\n", 2);
		return (-1);
	}
	if (fichier == NULL)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (1);
	}
	while (gets(ligne, sizeof(ligne), fichier) != NULL)
	{
		ft_putstr(ligne, 1);
	}
	close(fichier);
	return (0);
}
