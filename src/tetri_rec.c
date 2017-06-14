/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:45:39 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/28 22:28:23 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		init(t_rec **t, char ***tab)
{
	if (!(*t = (t_rec*)malloc(sizeof(t_rec))))
		return (-1);
	(*t)->i = 0;
	(*t)->ret = 0;
	(*t)->line = NULL;
	(*t)->keep = ft_strnew(0);
	*tab = NULL;
	return (1);
}

char			**tetri_rec(int fd, int *nbt)
{
	int		counter;
	int		line_counter;
	char	**tab;
	t_rec	*t;

	counter = 0;
	line_counter = 0;
	if (!(init(&t, &tab)))
		return (NULL);
	while ((t->ret = get_next_line(fd, &(t->line))) > 0)
	{
		t->keep = ft_strjoin_clean(&(t->keep), &(t->line));
		t->keep = ft_strjoin_clean_char(&(t->keep), '\n');
		if (ft_strlen(t->line) == 0)
		{
			if (line_counter != 4)
				return (NULL);
			line_counter = -1;
			counter++;
		}
		line_counter++;
	}
	tab = ft_strsplit(t->keep, '\n');
	*nbt = counter;
	return (tab);
}
