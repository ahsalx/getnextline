/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:59 by aben-sal          #+#    #+#             */
/*   Updated: 2025/11/30 13:50:29 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	while (s1 && s1[i] && s1[i] != '\n')
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] && s2[i] != '\n')
		str[j++] = s2[i++];
	if (s2 && s2[i] == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (free(s1), str);
}

void	manage_buffer(char *buffer)
{
	int	end_idx;
	int	new_idx;

	end_idx = 0;
	new_idx = 0;
	while (buffer[end_idx] && buffer[end_idx] != '\n')
		end_idx++;
	if (buffer[end_idx] == '\n')
		end_idx++;
	while (buffer[end_idx])
		buffer[new_idx++] = buffer[end_idx++];
	while (new_idx < BUFFER_SIZE)
		buffer[new_idx++] = '\0';
	buffer[new_idx] = '\0';
}

char	*read_and_join_line(int fd, char *line, char *rest)
{
	int	bytes;

	bytes = 1;
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		bytes = read(fd, rest, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		rest[bytes] = '\0';
		line = ft_strjoin(line, rest);
		if (!line)
			return (NULL);
	}
	return (line);
}
