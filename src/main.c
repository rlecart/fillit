/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:21:15 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:25:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_error(void)
{
	ft_putstr("error\n");
	exit(-1);
	return (-1);
}

int				main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		nbt;
	char	**game;
	char	**tetri;

	i = 0;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(tetri = tetri_rec(fd, &nbt)))
			return (ft_error());
		close(fd);
		if (!(game = fillit(tetri, nbt)))
			return (ft_error());
		ft_strtabdel(&tetri);
		ft_puttab(game);
		ft_strtabdel(&game);
	}
	return (0);
}
