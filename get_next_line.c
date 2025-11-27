/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:55:48 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/11/27 15:46:26 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buff)
{
	char	*line;
	int		linelen;
	int		i;

	if (!buff)
		return (NULL);
	linelen = 0;
	while (buff[linelen] != '\0' && buff[linelen] != '\n')
		linelen++;
	line = malloc(sizeof(char) * (linelen + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i < linelen)
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*readjust_buff(char *buff)
{
	char	*new_buff;
	int		i;
	int		j;

	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	new_buff = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!new_buff)
		return (free(buff), NULL);
	j = 0;
	while (buff[i])
		new_buff[j++] = buff[i++];
	new_buff[j] = '\0';
	free(buff);
	return (new_buff);
}

char	*read_to_buff(char *buff, int fd)
{
	char *temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, temp, BUFFER_SIZE);
	buff = ft_strjoin(buff, temp);
	free (temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	//char		*line;
	//int			fdlen;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buff = read_to_buff(buff, fd);
	/*buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	fdlen = read(fd, buff, BUFFER_SIZE);
	if (fdlen <= 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff[fdlen] = '\0';
	line = extract_line(buff);
	buff = readjust_buff(buff);*/
	return (buff);
}

int main()
{
	char *s, *s2;
	int fd;

	fd = open("hello.txt", O_RDWR);
	s = get_next_line(fd);
	s2 = get_next_line(fd);
	printf("1: %s\n2: %s", s, s2);
	
}