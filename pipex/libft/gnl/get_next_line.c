/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:08:48 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 18:04:54 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static void	*ft_gnl_memmove(void *dst, void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = n - 1;
		while (n--)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

char	*format_line(char *str)
{
	char	*line;
	int		i;
	int		k;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(str), NULL);
	k = 0;
	while (k < i)
	{
		line[k] = str[k];
		k++;
	}
	line[k] = '\0';
	free(str);
	return (line);
}

static void	ft_gnl_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

void	format_buf(char *str)
{
	char	*buf;
	int		i;
	int		length;
	int		after;

	i = 0;
	length = 0;
	buf = str;
	if (!str)
	{
		ft_gnl_bzero(buf, ft_gnl_strlen(buf));
		return ;
	}
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] && buf[i] == '\n')
		i++;
	while (buf[i++])
		length++;
	i -= length + 1;
	after = (int)ft_gnl_strlen(buf) - i;
	buf = (char *)ft_gnl_memmove(&buf[0], &buf[i], (size_t)length);
	ft_gnl_bzero(&buf[after], ft_gnl_strlen(&buf[after]));
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	b_read = BUFFER_SIZE;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) != 0)
		return (ft_gnl_bzero(buf, ft_gnl_strlen(buf)), NULL);
	line = NULL;
	if (buf[0] != '\0')
		line = add_buf(line, buf);
	while (b_read > 0 && !ft_gnl_strchr(buf, '\n'))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		buf[b_read] = '\0';
		if (b_read <= 0)
			break ;
		line = add_buf(line, buf);
	}
	line = format_line(line);
	format_buf((char *)buf);
	return (line);
}
