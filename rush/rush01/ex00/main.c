/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:20:58 by jeada-si          #+#    #+#             */
/*   Updated: 2023/09/17 13:55:11 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_read_param(char argv[1], int tab[16]);
int		ft_is_valid_value(int tab[4][4], int row_i, int col_i, int param[16]);
int		ft_solve(int tab[4][4], int param[16], int row, int col);
void	ft_print(int tab[4][4]);
void	ft_init_grid(int grid[4][4]);
int		ft_check_param(char	*str);
void	ft_print_error(void);

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	param[16];

	if (argc == 2 && ft_check_param(argv[1]))
	{
		ft_init_grid(grid);
		ft_read_param(argv[1], param);
		if (ft_solve(grid, param, 0, 0))
			ft_print(grid);
		else
			ft_print_error();
	}
	else
		ft_print_error();
}
