/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:56:14 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/11/26 17:32:23 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
char	*extract_line(char *buff);
char	*readjust_buff(char *buff);
size_t	ft_strlen(char *s);

#endif