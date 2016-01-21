/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:40:37 by adespond          #+#    #+#             */
/*   Updated: 2016/01/21 08:24:26 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_data	*new_data(int fd)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->last = ft_strnew(BUFF_SIZE);
	data->next = NULL;
	data->fd = fd;
	return (data);
}

t_data	*get_data(t_data *begin_data, int fd)
{
	t_data	*data;

	data = begin_data;
	while (data)
	{
		if (data->fd == fd)
			return (data);
		if (data->next == NULL)
		{
			data->next = new_data(fd);
			return (data->next);
		}
		data = data->next;
	}
	return (NULL);
}

int		ft_line(t_data *data, char *buff, char **line, int ret)
{
	buff = data->last;
	data->last = ft_strnew(BUFF_SIZE);
	while (1)
	{
		if (buff[0] == '\0')
		{
			ret = read(data->fd, buff, BUFF_SIZE);
			if (ret <= 0)
				return (ret);
			buff[BUFF_SIZE] = '\0';
		}
		if ((data->last = ft_strchr(buff, '\n')) != NULL)
		{
			data->last++;
			buff = ft_strsub(buff, 0, ft_strchrpos(buff, '\n'));
			*line = ft_strjoin(*line, buff);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, buff);
			buff = ft_strnew(BUFF_SIZE);
		}
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_data	*begin_data;
	t_data			*data;
	char			*buff;
	int				ret;

	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (begin_data == NULL)
		begin_data = new_data(fd);
	buff = ft_strnew(BUFF_SIZE);
	data = get_data(begin_data, fd);
	*line = ft_strnew(BUFF_SIZE);
	ret = ft_line(data, buff, line, ret);
	free(buff);
	return (ret);
}
