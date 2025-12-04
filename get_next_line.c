/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:26:06 by aben-sal          #+#    #+#             */
/*   Updated: 2025/12/04 15:19:04 by aben-sal         ###   ########.fr       */
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
	if (left[0] != '\0')
		line = ft_strjoin(line, left);
	while (!ft_strchr(line, '\n'))
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

/* int main()
{
	int fd = open("tet.txt", O_RDONLY);
	int fd2 = open("tet1.txt", O_RDONLY);
	char *line;
	char *line1;
	int  i = 0;
	while(i < 10)
	{
		line = get_next_line(fd);
		write(1, line, ft_strlen(line));
		free(line);
		line1 = get_next_line(fd2);
		write(1, line1, ft_strlen(line1));
		free(line1);
		i++;
	}
	printf("%d\n", i);
} */