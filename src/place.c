/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:31:23 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:26:31 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_place(char **map, int **pos, int x, int y)
{
	int		len;
	int		a[4];
	int		b[4];

	len = ft_strlen(map[0]);
	a[0] = pos[0][0] + y;
	a[1] = pos[1][0] + y;
	a[2] = pos[2][0] + y;
	a[3] = pos[3][0] + y;
	b[0] = pos[0][1] + x;
	b[1] = pos[1][1] + x;
	b[2] = pos[2][1] + x;
	b[3] = pos[3][1] + x;
	if (a[0] < len && a[1] < len && a[2] < len && a[3] < len
			&& b[0] < len && b[1] < len && b[2] < len && b[3] < len
			&& map[a[0]][b[0]] == '.'
			&& map[a[1]][b[1]] == '.'
			&& map[a[2]][b[2]] == '.'
			&& map[a[3]][b[3]] == '.')
		return (1);
	return (0);
}

void	ft_put_tetri(char **map, int **pos, int c[2], int i)
{
	int		a[4];
	int		b[4];

	a[0] = pos[0][0] + c[1];
	a[1] = pos[1][0] + c[1];
	a[2] = pos[2][0] + c[1];
	a[3] = pos[3][0] + c[1];
	b[0] = pos[0][1] + c[0];
	b[1] = pos[1][1] + c[0];
	b[2] = pos[2][1] + c[0];
	b[3] = pos[3][1] + c[0];
	map[a[0]][b[0]] = 'A' + i;
	map[a[1]][b[1]] = 'A' + i;
	map[a[2]][b[2]] = 'A' + i;
	map[a[3]][b[3]] = 'A' + i;
}

void	ft_rem_tetri(char **map, int **pos, int x, int y)
{
	int		a[4];
	int		b[4];

	a[0] = pos[0][0] + y;
	a[1] = pos[1][0] + y;
	a[2] = pos[2][0] + y;
	a[3] = pos[3][0] + y;
	b[0] = pos[0][1] + x;
	b[1] = pos[1][1] + x;
	b[2] = pos[2][1] + x;
	b[3] = pos[3][1] + x;
	map[a[0]][b[0]] = '.';
	map[a[1]][b[1]] = '.';
	map[a[2]][b[2]] = '.';
	map[a[3]][b[3]] = '.';
}
