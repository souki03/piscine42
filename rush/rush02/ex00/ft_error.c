/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:19:17 by dferrari          #+#    #+#             */
/*   Updated: 2023/09/24 17:17:42 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_error(void)
{
	char	*message_error[5];

	*message_error = "Error";
	ft_putstr(*message_error);
	ft_putchar('\n');
}

void	ft_print_dict_error(void)
{
	char	*message_error[11];

	*message_error = "Dict Error";
	ft_putstr(*message_error);
	ft_putchar('\n');
}
