/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:37 by daniviei          #+#    #+#             */
/*   Updated: 2025/12/02 16:57:45 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#define MAX_FD 1024

static char	*gnljoin(char **s1, char *s2);

static char	*readed(char **h)
{
	char	*str;
	int		i;
	char	*tmp;

	i = 0;
	str = ft_calloc(ft_strlen(*h) + 2, sizeof(char));
	while (h[0][i] != '\0' && h[0][i] != '\n')
	{
		str[i] = h[0][i];
		i++;
	}
	if (h[0][i] == '\n')
		str[i++] = '\n';
	if (str[0] == '\0')
	{
		free(*h);
		free(str);
		*h = NULL;
		return (NULL);
	}
	tmp = ft_strdup(*h + i);
	free(*h);
	*h = tmp;
	return (str);
}

static char	*read_line(char **holder, int fd)
{
	char	*buffer;
	ssize_t	counter;

	buffer = ft_calloc((unsigned int)BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	counter = read(fd, buffer, BUFFER_SIZE);
	while (counter > 0)
	{
		buffer[counter] = '\0';
		*holder = gnljoin(holder, buffer);
		if (strchr(*holder, '\n'))
			break ;
		counter = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (readed(holder));
}

char	*get_next_line(int fd)
{
	static char	*holder[MAX_FD];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!holder[fd])
		holder[fd] = ft_calloc(1, 1);
	return (read_line(&holder[fd], fd));
}

static char	*gnljoin(char **s1, char *s2)
{
	int		i;
	int		ni;
	size_t	size;
	char	*nstr;

	i = 0;
	ni = 0;
	size = (ft_strlen(s1[0]) + ft_strlen(s2)) * sizeof(char);
	nstr = (char *)malloc(size + 1);
	if (!nstr)
		return (NULL);
	while (s1[0][i] != '\0')
	{
		nstr[ni] = s1[0][i];
		ni++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		nstr[ni++] = s2[i++];
	}
	nstr[ni] = '\0';
	free(s1[0]);
	return (nstr);
}
