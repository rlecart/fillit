/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:57:05 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:26:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map(char **del, int nbtetri, int add)
{
	int		i;
	int		j;
	int		counter;
	char	**map;

	i = 0;
	j = 0;
	counter = (int)ft_sqrt(4 * nbtetri) + add;
	if (!(map = ft_tabnew(counter, counter)))
		return (NULL);
	while (i < counter)
	{
		while (j < counter)
			map[i][j++] = '.';
		i++;
		j = 0;
	}
	if (del)
		ft_strtabdel(&del);
	return (map);
}
