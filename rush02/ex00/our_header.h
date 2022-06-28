/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:41:04 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/28 22:10:56 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OUR_HEADER_H
# define OUR_HEADER_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		get_file_size(char *file_name);
char	*get_dictionary(char *file_name);
int		is_printable(char c);
int		my_isspace(char c);
int		check_line_syntaxe(char *str);
int		check_syntaxe(char *dict);
int		is_valid_uint(char *str);
char	**get_values(char *dict, char **entries);
void	strcpy_value(char *s1, char *s2);
int		size_value(char *value);
char	*find_value(char *dict, char *to_find);
char	*find_value_in_line(char *dict, char *to_find);
void	ft_init(char **tab);
int		ft_init_bis(char **tab);
char	*isolate_number(char *str);
int		check_err(char *file_name, char *uint, char **entries, char ***value);
void	ft_bloc3(char *s, char **tab);
void	ft_bloc2(char *s, char **tab);
int		ft_len(char *s);
void	ft_putchar_trim(char *tab);
void	write_number(char *nb, char **trad);
char	*get_n_char(char *str, unsigned int n);
int		only_zeros(char *str);
void	write_first_rank(char *nb_cut, char **trad, int n, int nb_blocks);
void	write_rank(char *nb_cut, char **trad, int i, int nb_blocks);

#endif
