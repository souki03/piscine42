/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:47:36 by rdupeux           #+#    #+#             */
/*   Updated: 2023/09/24 23:07:10 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef FT_H
# define FT_H

typedef struct t_dict
{
	char	*key;
	char	*value;
}			s_dict;
// place prototype here
void		ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_strlen(char *str);
int			is_space(char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_update_res(char *s1, char *s2);
char		*get_array(char a, char b, char c);
int			ft_dict_count_line(char *file);
char		*ft_dict_get(char *name_of_file);
int			get_len_to_add(char *str);
char		*set_ten(char *res, char *str, s_dict *dict);
char		*set_hundred(char *res, char *str, s_dict *dict);
void		ft_print_error(void);
void		ft_print_dict_error(void);
char		**ft_dic_split(char *str);
char		*gen_res(s_dict *dict, char *str, char *res);
s_dict		*get_dict(char *str);
char		*get(char *c, s_dict *dict);
char		*get_array(char a, char b, char c);
char		*normalyze_input(char *str);
char		*create_power(int len);
void		free_dict(s_dict *dict);
int			is_sep(char c, char *charset);
s_dict		*merge_dict(s_dict *dict_base, s_dict *dict_add);

#endif