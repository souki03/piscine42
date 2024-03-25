/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:25:19 by rdupeux           #+#    #+#             */
/*   Updated: 2023/09/24 21:47:06 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

s_dict *merge_dict(s_dict *dict_base, s_dict *dict_add)
{
	int i;
	int j;

	i = 0;
	if (!dict_add)
		return (dict_base);
	while (dict_base[i].key)
	{
		j = 0;
		while (dict_add[j].key)
		{
			if (dict_base[i].key == dict_add[j].key)
				dict_base[i].value = dict_add[j].value;
			j++;
		}
		i++;
	}
	free_dict(dict_add);
	return (dict_base);
}
