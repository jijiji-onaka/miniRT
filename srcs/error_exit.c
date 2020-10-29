/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:19:59 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:03:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"
#include "../includes/list_all.h"

void	exit_put(char *s)
{
	if (s == NULL)
		return ;
	ft_putstr_fd("Error\n", 1);
	ft_putendl_fd(s, 1);
	exit(1);
}

void	free_all_and_exit_put(t_all *all, char *s)
{
	free_all(all);
	exit_put(s);
}

void	read_file_error(int rc, t_all *all, char *s)
{
	if (rc < 0)
		free_all_and_exit_put(all, ERR_READ);
	if (all->r == NULL)
		free_all_and_exit_put(all, ERR_RESOLUTION2);
	if (s != NULL)
		free_all_and_exit_put(all, s);
}

int		exit_perror(char *s)
{
	ft_putstr_fd("Error\n", 1);
	perror(s);
	exit(1);
}

char	*check_out_of_range(double num, double min, double max, char *obj_elem)
{
	char	error_message[100];
	size_t	len;

	len = ft_strlen(obj_elem);
	if (num < min || num > max)
	{
		ft_strlcpy(error_message, obj_elem, len + 1);
		ft_strlcat(error_message, " is Out of Range .]\n", 20 + len + 2);
		ft_putstr_fd(error_message, 1);
		return (ERR_VALUE_OVER);
	}
	return (NULL);
}
