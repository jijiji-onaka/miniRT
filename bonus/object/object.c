/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 01:48:52 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:03:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	clear_olst(t_objs_info **olst)
{
	if (*olst == NULL)
		return ;
	clear_olst(&((*olst)->next));
	free(*olst);
}

void	olstadd_back(t_objs_info **olst, t_objs_info *new)
{
	if (!olst)
		return ;
	if (!*olst)
		*olst = new;
	else
		olstadd_back(&((*olst)->next), new);
}
