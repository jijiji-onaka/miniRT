/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:47:09 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/25 16:01:28 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_ex(char const *s1, char const *s2, int *rc)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;

	if (s1 == NULL || s2 == NULL)
	{
		*rc = -1;
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
	{
		*rc = -1;
		return (NULL);
	}
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}

static char	*ft_strchr_ex(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char*)s);
	return (NULL);
}

static char	*ft_strdup_ex(char *s1, int *tmp_rc)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (s1 == NULL)
		return (ft_strdup_ex("", tmp_rc));
	len = ft_strlen(s1);
	if (!(res = malloc(sizeof(char) * (len + 1))))
	{
		*tmp_rc = -1;
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static	int	gnl_read(int fd, char **stock, int rc)
{
	char	*buf;
	char	*tmp;
	int		tmp_rc;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	tmp_rc = read(fd, buf, BUFFER_SIZE);
	if (tmp_rc >= 0 && rc != -1)
		buf[tmp_rc] = '\0';
	if (stock[fd] == NULL && tmp_rc > 0 && rc != -1)
		stock[fd] = ft_strdup_ex(buf, &tmp_rc);
	else if (stock[fd] != NULL && rc != -1 && tmp_rc > 0)
	{
		tmp = stock[fd];
		stock[fd] = ft_strjoin_ex(tmp, buf, &tmp_rc);
		free(tmp);
		tmp = NULL;
	}
	free(buf);
	if ((tmp_rc == -1 && stock[fd]) || (rc == -1 && stock[fd]))
	{
		free(stock[fd]);
		stock[fd] = NULL;
	}
	return ((rc == -1) ? -1 : tmp_rc);
}

int			get_next_line(int fd, char **line)
{
	static char *stock[FD_MAX];
	char		*newline;
	char		*tmp;
	int			rc;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > FD_MAX)
		return (-1);
	rc = 1;
	while (!ft_strchr_ex(stock[fd], '\n') && (rc = gnl_read(fd, stock, rc)) > 0)
		if (rc < 0 || !stock[fd])
			return (-1);
	newline = ft_strchr_ex(stock[fd], '\n');
	if (newline != NULL)
	{
		*line = ft_substr(stock[fd], 0, newline - stock[fd]);
		tmp = stock[fd];
		stock[fd] = ft_strdup_ex(newline + 1, &rc);
		free(tmp);
		tmp = NULL;
		return ((*line == NULL || rc < 0) ? -1 : 1);
	}
	*line = ft_strdup_ex(stock[fd], &rc);
	free(stock[fd]);
	stock[fd] = NULL;
	return ((*line == NULL || rc < 0) ? -1 : 0);
}
