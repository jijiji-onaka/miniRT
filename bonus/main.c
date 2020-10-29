/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:22:38 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:03:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			main(int argc, char *argv[])
{
	t_all		all;
	char		*message;

	if (!(argc == 2 || (argc == 3 && ft_memcmp(argv[2], "--save", 7) == 0)))
		exit_put(ERR_ARG);
	read_file(&all, argv[1]);
	message = minirt(argv[1], &all, argc == 3);
	free_all(&all);
	if (message != NULL)
		exit_put(message);
	return (0);
}
