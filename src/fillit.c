/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill-it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:41:17 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:25:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_tetri_letter(char ***str)
{
	int		i;
	int		j;
	int		k;
	char	c;

	i = -1;
	j = -1;
	k = -1;
	c = 'A';
	while (str[++i])
	{
		while (str[i][++j])
		{
			while (str[i][j][++k])
				if (str[i][j][k] == '#')
					str[i][j][k] = c;
			k = -1;
		}
		c++;
		j = -1;
	}
}

static char		***ft_verif_al(char ***str, int i[5])
{
	while (str[++i[0]])
	{
		while (str[i[0]][++i[1]])
		{
			while (str[i[0]][i[1]][++i[2]])
				if (str[i[0]][i[1]][i[2]] != '.')
				{
					if (i[1] != 3 && str[i[0]][i[1] + 1][i[2]] != '.')
						i[3]++;
					if (i[1] != 0 && str[i[0]][i[1] - 1][i[2]] != '.')
						i[3]++;
					if (i[2] != 3 && str[i[0]][i[1]][i[2] + 1] != '.')
						i[3]++;
					if (i[2] != 0 && str[i[0]][i[1]][i[2] - 1] != '.')
						i[3]++;
					i[4]++;
				}
			i[2] = -1;
		}
		if ((i[3] != 6 && i[3] != 8) || i[4] != 4)
			return (NULL);
		ft_memcpy(i, ((int[5]){i[0], -1, -1, 0, 0}), sizeof(int[5]));
	}
	return (str);
}

static char		***ft_tetri_cat(char **tetri, int nbtetri)
{
	int		i;
	int		j;
	int		k;
	char	***str;

	i = 0;
	j = 0;
	k = 0;
	str = NULL;
	if (!(str = (char***)malloc(sizeof(char**) * (nbtetri + 1))))
		return (NULL);
	str[nbtetri] = NULL;
	while (i < nbtetri)
	{
		if (!(str[i] = (char**)malloc(sizeof(char*) * 5)))
			return (NULL);
		while (j < 4)
			if (!(str[i][j++] = ft_strdup(tetri[k++])))
				return (NULL);
		str[i][j] = NULL;
		i++;
		j = 0;
	}
	ft_tetri_letter(str);
	return (ft_verif_al(str, ((int[5]){-1, -1, -1, 0, 0})));
}

static int		ft_verif(char **tetri)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tetri[i]))
		return (-1);
	while (tetri[i])
	{
		if (ft_strlen(tetri[i]) != 4)
			return (-1);
		while (tetri[i][j])
		{
			if (tetri[i][j] != '#' && tetri[i][j] != '.' && tetri[i][j] != '\n')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	if (i % 4 != 0 || i > (26 * 4))
		return (-1);
	return (i / 4);
}

char			**fillit(char **tetri, int nbt)
{
	int		i;
	int		nbtetri;
	char	**game;
	char	***tetri_tab;

	i = 0;
	if ((nbtetri = ft_verif(tetri)) == -1)
		return (NULL);
	if (nbtetri - 1 != nbt)
		return (NULL);
	if (!(tetri_tab = ft_tetri_cat(tetri, nbtetri)))
		return (NULL);
	if (!(game = ft_tetri_pos(tetri_tab, nbtetri)))
		return (NULL);
	while (tetri_tab[i])
	{
		ft_strtabdel(&(tetri_tab[i]));
		free(tetri_tab[i++]);
	}
	free(tetri_tab);
	return (game);
}
