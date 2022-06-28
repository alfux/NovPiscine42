/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:02:27 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/01 14:19:54 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H_H
# define FT_H_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_coord
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
}					t_coord;

typedef struct s_sqre
{
	unsigned int	i_u;
	unsigned int	i_d;
	unsigned int	j_r;
	unsigned int	j_l;
}					t_sqre;

typedef struct s_map
{
	unsigned int	lin;
	unsigned int	col;
	unsigned int	nb_obs;
	t_coord			*obst;
}					t_map;

typedef struct s_info
{
	char			empty;
	char			obs;
	char			bsq;
	unsigned int	lines;
}					t_info;

int				valid_square(t_sqre *sqr, t_map map);
int				is_not_full(t_map map);
char			*draw_sqre(t_sqre sqr, char *str_map, t_info info);
void			mod_sqr(t_sqre *sqr, int i, int j, int size);
int				min_of(int n, int m);
char			*ft_resolve(char *s_map, t_coord m_sz, t_map map, t_info info);
unsigned int	get_nb_obs(char *map);
void			mod_coord(t_coord *coord, int i, int j, int k);
t_coord			*get_obs_coords(char *map, unsigned int nb_obs);
void			ft_init_t_map(char *str_map, t_map *map);
char			*get_map_str(char *file_name);
int				get_file_size(char *file_name);
int				ft_map_argv(char *argv);
char			*ft_stdin(void);
int				ft_map_stdin(char *stdin);
int				ft_check_map(char *map, t_info *info);
int				ft_firstline(char *map);
int				ft_lines_nbr(char *map, int l);
int				ft_check_lines(char *map, t_info info);
int				ft_check_lines2(char *map, t_info *info, int l, int *start);
#endif
