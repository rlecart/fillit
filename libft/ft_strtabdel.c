/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:11:14 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/01 15:16:00 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabdel(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
		ft_strdel(&(*tab)[i++]);
	ft_strdel(*tab);
}
