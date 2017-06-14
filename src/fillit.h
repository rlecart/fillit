/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:41:26 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:24:51 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct		s_rec
{
	int				i;
	int				ret;
	char			*line;
	char			*keep;
}					t_rec;

typedef struct		s_rec_pos
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				x;
	int				y;
}					t_rec_pos;

typedef struct		s_tetri_pos
{
	int				sr[2];
	int				*(c[2]);
	int				***pos;
	char			**map;
}					t_tetri_pos;

char				**fillit(char **tetri, int nbt);
char				**tetri_rec(int fd, int *nbt);
char				**ft_tetri_pos(char ***tetri_tab, int nbtetri);
void				ft_rem_tetri(char **map, int **pos, int x, int y);
void				ft_put_tetri(char **map, int **pos, int c[2], int i);
int					ft_check_place(char **map, int **pos, int x, int y);
void				ft_rec_pos(int ***pos, char ***tetri_tab);
char				**ft_map(char **del, int nbtetri, int add);
int					***ft_init_pos(int nbtetri);
void				ft_free_pos(int ***pos, int nbtetri);

#endif
