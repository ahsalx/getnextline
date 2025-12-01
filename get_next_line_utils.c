/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:26:09 by aben-sal          #+#    #+#             */
/*   Updated: 2025/12/01 19:38:13 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2 && s2[i])
	{
		newstr[j] = s2[i];
		j++;
		i++;
	}
	newstr[j] = '\0';
	return (free(s1), newstr);
}

char	*normleft(char *line, char *left)
{
	char	*nl;
	size_t	i;

	if (!line || line[0] == '\0')
		return (free(line), NULL);
	nl = ft_strchr(line, '\n');
	if (nl)
	{
		nl++;
		i = 0;
		while (nl[i])
		{
			left[i] = nl[i];
			i++;
		}
		left[i] = '\0';
		nl[0] = '\0';
	}
	else
		left[0] = '\0';
	return (line);
}
