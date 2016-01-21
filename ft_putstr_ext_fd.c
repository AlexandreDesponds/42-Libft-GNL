/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:52:50 by adespond          #+#    #+#             */
/*   Updated: 2015/11/27 12:51:23 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_putstr_ext_fd(int const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		printf("\n-- %d --\n", s[i]);
		ft_putchar_ext_fd(s[i], fd);
		i++;
	}
}
