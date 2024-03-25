/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:57:28 by jeada-si          #+#    #+#             */
/*   Updated: 2023/09/20 12:40:28 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

int		*ft_get_col(int tab[4][4], int col[4], int c);
int		*ft_get_row(int tab[4][4], int row[4], int r);
int		ft_is_line_valid(int tab[4], int view_val_1, int view_val_2, int index);
void	ft_print(int tab[4][4]);

/*Validity function that checks that the new number fit for
the considered column and row*/
// int	ft_is_valid_value(int tab[4][4], int row_i, int col_i, int param[16])
// {
// 	int	col[4];
// 	int	row[4];
// 	int	col_ok;
// 	int	row_ok;

// 	ft_get_col(tab, col, col_i);
// 	ft_get_row(tab, row, row_i);
// 	col_ok = ft_is_line_valid(col, param[col_i], param[col_i + 4], row_i);
// 	if (!col_ok)
// 		return (0);
// 	row_ok = ft_is_line_valid(row, param[8 + row_i], param[12 + row_i], col_i);
// 	if (!row_ok)
// 		return (0);
// 	return (1);
// }

// /*Recursive solver*/
// int	ft_solve(int tab[4][4], int param[16], int row, int col)
// {
// 	int	i;

// 	if (row == 3 && col == 4)
// 		return (1);
// 	if (col == 4)
// 	{
// 		row++;
// 		col = 0;
// 	}
// 	if (tab[row][col] != 0)
// 		return (ft_solve(tab, param, row, col + 1));
// 	i = 1;
// 	while (i <= 4)
// 	{
// 		tab[row][col] = i;
// 		if (ft_is_valid_value(tab, row, col, param))
// 		{
// 			if (ft_solve(tab, param, row, col + 1))
// 				return (1);
// 		}
// 		tab[row][col] = 0;
// 		i++;
// 	}
// 	return (0);
// }

// Below is a verbose version to understand backtracking.
#include<stdio.h>
#include<unistd.h>

#define FG_RED		"\x1b[31m"
#define FG_BLACK	"\x1b[30m"
#define FG_GREEN 	"\x1b[32m"
#define FG_WHITE	"\x1b[37m"
#define BG_RED		"\x1b[41m"
#define BG_BLACK	"\x1b[40m"

int		*ft_get_col(int tab[4][4], int col[4], int c);
int		*ft_get_row(int tab[4][4], int row[4], int r);
int		ft_is_line_valid(int tab[4], int view_val_1, int view_val_2, int index);
void	ft_print(int tab[4][4]);

int	ft_is_valid_value(int tab[4][4], int row_i, int col_i, int param[16])
{
	int	col[4];
	int	row[4];
	int	col_ok;
	int	row_ok;

	ft_get_col(tab, col, col_i);
	ft_get_row(tab, row, row_i);
	col_ok = ft_is_line_valid(col, param[col_i], param[col_i + 4], row_i);
	if (col_ok)
		printf("%sFit in column %d%s\n", FG_GREEN, col_i, FG_WHITE);
	else
		printf("%sDoes not fit in column %d%s\n", FG_RED, col_i, FG_WHITE);
	if (!col_ok)
		return (0);
	row_ok = ft_is_line_valid(row, param[8 + row_i], param[12 + row_i], col_i);
	if (row_ok)
		printf("%sFit in row %d%s\n", FG_GREEN, row_i, FG_WHITE);
	else
		printf("%sDoes not fit in row %d%s\n", FG_RED, row_i, FG_WHITE);
	if(!row_ok)
		return(0);
	return(1);
}

int	ft_solve(int tab[4][4], int param[16], int row, int col)
{
	int	i;

	if (row == 3 && col == 4)
		return (1);
	if (col == 4)
	{
		row++;
		col = 0;
	}
	if(tab[row][col] != 0)
		return ft_solve(tab, param, row, col + 1);
	i = 1;
	while(i <= 4)
	{
		tab[row][col] = i;
		printf("_______________________________\n");
		ft_print(tab);		
		printf("Row %d, Col %d, trying number %d\n", row, col, i);
		if (ft_is_valid_value(tab, row, col, param))
		{
			printf("Number %d seems valid\n", i);
			if (ft_solve(tab, param, row, col + 1))
				return (1);
		}
		printf("Row %d, Col %d, number %d does not fit.\n", row, col, i);
		tab[row][col] = 0;
		i++;
	}
	printf("_______________________________\n");
	printf("\n%sNo solutions found. Backtracking.%s\n", BG_RED, BG_BLACK);
	return (0);
}

