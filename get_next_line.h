/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:25:52 by adespond          #+#    #+#             */
/*   Updated: 2016/01/21 13:58:24 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include <fcntl.h>
# include "libft.h"

int		get_next_line(int const fd, char **line);

typedef struct		s_data
{
	char			*last;
	int				fd;
	struct s_data	*next;
}					t_data;

int					get_next_line(int const fd, char **line);
#endif
