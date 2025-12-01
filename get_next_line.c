/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:26:06 by aben-sal          #+#    #+#             */
/*   Updated: 2025/12/01 19:30:28 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	left[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes = 1;
	if (left[0] != '\0')
		line = ft_strjoin(line, left);
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		bytes = read(fd, left, BUFFER_SIZE);
		if (bytes < 0)
			return (free(line), NULL);
		if (bytes == 0)
			break ;
		left[bytes] = '\0';
		line = ft_strjoin(line, left);
		if (!line)
			return (NULL);
	}
	return (normleft(line, left));
}
