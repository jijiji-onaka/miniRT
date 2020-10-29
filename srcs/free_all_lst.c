/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:33:11 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:03:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	free_all(t_all *all)
{
	free(all->r);
	free(all->a);
	clear_clst(&(all->clst));
	clear_llst(&(all->llst));
	clear_olst(&(all->olst));
}
