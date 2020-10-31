/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:53:08 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 09:08:41 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_file.h"

static void	init_info(t_all *all)
{
	all->a = NULL;
	all->r = NULL;
	all->clst = NULL;
	all->llst = NULL;
	all->olst = NULL;
	all->current_c = 0;
}

static char	*parse_obj(char **p, t_objs_info **olst)
{
	t_objs_info	*new;
	char		*(*const parse_each_obj[])(char **, void *) = {
		parse_sphere, parse_plane, parse_square,
		parse_triangle, parse_cylinder, parse_cube,
	//	parse_pyramid,
	};

	if (!MALLOC(new, 1))
		return (ERR_MALLOC);
	new->next = NULL;
	olstadd_back(olst, new);
	new->type = hash(p[0]);
	if (new->type == -1)
		return (ERR_RT_FORMAT4);
	return (parse_each_obj[new->type](p + 1, &(new->obj)));
}

static char	*parse_info(t_all *all, char *line)
{
	char		*res;
	char		**p;

	res = NULL;
	if (line[0] == '\0' || line[0] == '#')
		return (res);
	if (!(p = ft_split(line, ' ')))
		return (ERR_MALLOC);
	if (count_2d(p) == 0)
		res = ERR_RT_FORMAT;
	if (count_2d(p) == 1)
		res = ERR_RT_FORMAT5;
	else if (ft_strcmp(p[0], "c") == 0)
		res = parse_camera(p + 1, &(all->clst));
	else if (ft_strcmp(p[0], "l") == 0)
		res = parse_light(p + 1, &(all->llst));
	else if (ft_strcmp(p[0], "A") == 0)
		res = parse_ambient_light(p + 1, &(all->a));
	else if (ft_strcmp(p[0], "R") == 0)
		res = parse_resolution(p + 1, &(all->r));
	else
		res = parse_obj(p, &(all->olst));
	array_free_2d(&p, count_2d(p));
	return (res);
}

void		read_file(t_all *all, char *filename)
{
	char		*line;
	int			fd;
	int			rc;
	char		*message;

	if (!(check_file_tail(filename, "rt")))
		exit_put(ERR_FILETAIL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_perror(ERR_OPEN);
	init_info(all);
	rc = 0;
	message = NULL;
	while ((rc = get_next_line(fd, &line)) >= 0)
	{
		message = parse_info(all, line);
		free(line);
		if (rc == 0 || message != NULL)
			break ;
	}
	close(fd);
	if (rc < 0 || all->r == NULL || message != NULL)
		read_file_error(rc, all, message);
}
