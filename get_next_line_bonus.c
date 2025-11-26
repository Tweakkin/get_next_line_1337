/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:32:05 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/11/26 11:56:55 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	allocate_buff(int fd, char **buff)
{
	size_t	fdlen;
	
	*buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buff)
		return (0);
	fdlen = read(fd, *buff, BUFFER_SIZE);
	if (fdlen <= 0)
	{
		free(*buff);
		*buff = NULL;
		return (0);
	}
	(*buff)[fdlen] = '\0';
	return (fdlen);	
}

char *get_next_line(int fd)
{
	static char	*buff[FD_SIZE];
	char		*line;
	
	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if(!buff[fd])
	{
		if (allocate_buff(fd, &buff[fd]) == 0)
			return (NULL);
	}
	
}