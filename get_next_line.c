/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:56 by aben-sal          #+#    #+#             */
/*   Updated: 2025/11/30 13:20:52 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, rest);
	if (!line)
		return (NULL);
	line = read_and_join_line(fd, line, rest);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n'))
		manage_buffer(rest);
	else
		rest[0] = '\0';
	return (line);
}
