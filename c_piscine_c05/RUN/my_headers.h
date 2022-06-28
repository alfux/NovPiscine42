/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_headers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:40:42 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/25 12:41:27 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MY_HEADERS_H
# define MY_HEADERS_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <time.h>

int				ft_ten_queens_puzzle(void);
int				ft_find_next_prime(int nb);
int				ft_is_prime(int nb);
int				ft_sqrt(int nb);
int				ft_fibonacci(int index);
int				ft_iterative_power(int nb, int power);
int				ft_recursive_power(int nb, int power);
int				ft_iterative_factorial(int nb);
int				ft_recursive_factorial(int nb);
int				ft_atoi_base(char *str, char *base);
void			ft_putnbr_base(int nbr, char *base);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
char			*ft_strcat(char *dest, char *src);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
int				check_scrapers(int **tab, int *all_views);
void			*ft_print_memory(void *addr, unsigned int size);
void			ft_putstr_non_printable(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strcapitalize(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_uppercase(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_alpha(char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strcpy(char *dest, char *src);
void			ft_sort_int_tab(int *tab, int size);
void			ft_rev_int_tab(int *tab, int size);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_ultimate_div_mod(int *a, int *b);
void			ft_div_mod(int a, int b, int *div, int *mod);
void			ft_swap(int *a, int *b);
void			ft_ultimate_ft(int *********nbr);
void			ft_ft(int *nbr);
void			ft_putchar(char c);
void			ft_print_alphabet(void);
void			ft_print_reverse_alphabet(void);
void			ft_print_numbers(void);
void			ft_is_negative(int n);
void			ft_print_comb(void);
void			ft_print_comb2(void);
void			ft_putnbr(int nb);
void			ft_print_combn(int n);
#endif
