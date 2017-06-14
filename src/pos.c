/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:59:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:27:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_free_pos(int ***pos, int nbtetri)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nbtetri)
	{
		while (j <= 4)
			free(pos[i][j++]);
		free(pos[i++]);
		j = 0;
	}
	free(pos);
}

int				***ft_init_pos(int nbtetri)
{
	int		i;
	int		j;
	int		***pos;

	i = 0;
	j = 0;
	if (!(pos = (int***)malloc(sizeof(int**) * nbtetri)))
		return (NULL);
	while (i < nbtetri)
	{
		if (!(pos[i] = (int**)malloc(sizeof(int*) * 4)))
			return (NULL);
		while (j < 4)
		{
			if (!(pos[i][j] = ft_intnew(2)))
				return (NULL);
			pos[i][j][0] = 0;
			pos[i][j][1] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	return (pos);
}

static void		ft_s_init(t_rec_pos *r)
{
	r->i = -1;
	r->j = -1;
	r->k = -1;
	r->l = 0;
}

void			ft_rec_pos(int ***pos, char ***tetri_tab)
{
	t_rec_pos	r;

	ft_s_init(&r);
	while (tetri_tab[++(r.i)])
	{
		r.x = -1;
		r.y = -1;
		while (tetri_tab[r.i][++(r.j)])
		{
			while (tetri_tab[r.i][r.j][++(r.k)])
				if (tetri_tab[r.i][r.j][r.k] != '.')
				{
					pos[r.i][r.l][0] = r.j;
					pos[r.i][r.l][1] = r.k;
					r.x == -1 ? r.x = r.j : r.x;
					r.y == -1 ? r.y = r.k : r.y;
					pos[r.i][r.l][0] -= r.x;
					pos[r.i][(r.l)++][1] -= r.y;
				}
			r.k = -1;
		}
		r.j = -1;
		r.l = 0;
	}
}
