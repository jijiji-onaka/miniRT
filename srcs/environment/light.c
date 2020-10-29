/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:05:51 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:52:05 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/environment.h"

void		clear_llst(t_light **llst)
{
	if (*llst == NULL)
		return ;
	clear_llst(&((*llst)->next));
	free(*llst);
}

static void	llstadd_back(t_light **llst, t_light *new)
{
	if (!llst)
		return ;
	if (!*llst)
		*llst = new;
	else
		llstadd_back(&((*llst)->next), new);
}

char		*parse_light(char **p, t_light **llst)
{
	t_light *new;
	char	*tmp;

	if (count_2d(p) != 3)
		return (ERR_RT_FORMAT3);
	if (!MALLOC(new, 1))
		return (ERR_MALLOC);
	new->next = NULL;
	llstadd_back(llst, new);
	if (!ft_stov(p[0], &(new->pos)) ||
		!ft_stod(p[1], &(new->ratio)) ||
		!ft_stov(p[2], &(new->rgb)))
		return (ERR_RT_FORMAT2);
	if ((tmp = check_out_of_range(new->ratio, 0.0, 1.0,
			"[Light brightness_ratio")))
		return (tmp);
	if ((tmp = check_vec_range(new->rgb, 0, 255, "[Light color")))
		return (tmp);
	return (tmp);
}
