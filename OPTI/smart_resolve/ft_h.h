/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:02:27 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/01 04:32:19 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H_H
# define FT_H_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

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

typedef struct s_map2d
{
	unsigned int	lin;
	unsigned int	col;
	char			emp;
	char			obs;
	char			bsq;
	unsigned int	**map2d;
}					t_map2d;

typedef struct s_info
{
	char			empty;
	char			obs;
	char			bsq;
	unsigned int	lines;
}					t_info;

int		valid_square(t_sqre *sqr, t_map map);
char	*draw_sqre(t_sqre sqr, char *str_map, t_map2d info);
void	mod_sqr(t_sqre *sqr, int i, int j, int size);
int		min_of(int n, int m);
char	*ft_resolve(char *s_map, t_coord m_sz, t_map map, t_map2d info);
void	mod_coord(t_coord *coord, int i, int j, int k);
t_coord	*get_obs_coords(char *map, unsigned int nb_obs);
void	ft_init_t_map(char *str_map, t_map *map);
char	*get_map_str(char *file_name);
int		get_file_size(char *file_name);
void	get_map2d(char *str_map, t_map2d *map);
void	pre_resolve(t_map2d *map);
void	init_map2d(char *str_map, t_map2d *map);
int		s_valid_square(t_sqre *sqr, t_map2d map);
t_sqre	local_resolve(t_sqre zne, t_map2d map, t_coord size);
void	get_zone(t_sqre *zone, unsigned int i, unsigned int j, t_map2d map);
char	*smart_resolve(char *str);
#endif
