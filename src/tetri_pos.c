/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 03:03:14 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:27:56 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri_pos		*ft_init(char ***tetri_tab, int nbtetri)
{
	t_tetri_pos		*t;

	if (!(t = (t_tetri_pos*)malloc(sizeof(t_tetri_pos))))
		return (NULL);
	t->sr[0] = 0;
	t->c[0] = ft_intnew(nbtetri);
	t->c[1] = ft_intnew(nbtetri);
	t->map = NULL;
	if (!(t->pos = ft_init_pos(nbtetri)))
		return (NULL);
	ft_rec_pos(t->pos, tetri_tab);
	if (!(t->map = ft_map(t->map, nbtetri, t->sr[0])))
		return (NULL);
	return (t);
}

static int				ft_if(t_tetri_pos *t, int nbtetri, int *i)
{
	if (*i > 0)
	{
		t->c[0][*i] = 0;
		t->c[1][*i] = 0;
		(*i)--;
		ft_rem_tetri(t->map, t->pos[*i], t->c[0][*i], t->c[1][*i]);
		nbtetri++;
		t->c[0][*i]++;
		if (t->c[1][*i] >= (int)ft_strlen(t->map[0]))
		{
			t->c[0][*i] = 0;
			t->c[1][*i]++;
		}
	}
	else
	{
		if (!(t->map = ft_map(t->map, nbtetri, ++(t->sr[0]))))
			return (-1);
		t->c[0][*i] = 0;
		t->c[1][*i] = 0;
	}
	return (nbtetri);
}

static int				ft_while(t_tetri_pos *t, int nbtetri, int *i)
{
	if ((t->sr[1] = ft_check_place(t->map,
					t->pos[*i], t->c[0][*i], t->c[1][*i])))
	{
		ft_put_tetri(t->map,
				t->pos[*i], (int[2]){t->c[0][*i], t->c[1][*i]}, *i);
		nbtetri--;
		(*i)++;
	}
	else if (t->sr[1] == 0)
	{
		t->c[0][*i]++;
		if (t->c[0][*i] >= (int)ft_strlen(t->map[0]))
		{
			t->c[0][*i] = 0;
			t->c[1][*i]++;
			if (t->c[1][*i] >= (int)ft_strlen(t->map[0]))
				if ((nbtetri = ft_if(t, nbtetri, i)) == -1)
					return (-1);
		}
	}
	return (nbtetri);
}

char					**ft_tetri_pos(char ***tetri_tab, int nbtetri)
{
	int				i;
	t_tetri_pos		*t;

	i = 0;
	if (!(t = ft_init(tetri_tab, nbtetri)))
		return (NULL);
	while (nbtetri > 0)
	{
		if ((nbtetri = ft_while(t, nbtetri, &i)) == -1)
			return (NULL);
	}
	ft_free_pos(t->pos, nbtetri);
	return (t->map);
}
