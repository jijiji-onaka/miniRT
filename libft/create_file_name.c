/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 02:24:47 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 06:01:58 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strjoin_3(char *s1, char *s2, char *s3)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	if (!(res = malloc(len)))
		return (NULL);
	ft_strlcpy(res, s1, len);
	ft_strlcat(res, s2, len);
	ft_strlcat(res, s3, len);
	return (res);
}

char				*create_file_name(char *directory,
				char *file, char *extension)
{
	char	*tmp;
	char	*extension_file;

	if (!directory || !file || !extension)
		return (NULL);
	tmp = ft_substr(file, 0, ft_strrchr(file, '.') - file);
	if (!tmp)
		return (NULL);
	extension_file = ft_strjoin_3(directory, tmp, extension);
	free(tmp);
	if (!extension_file)
		return (NULL);
	return (extension_file);
}
