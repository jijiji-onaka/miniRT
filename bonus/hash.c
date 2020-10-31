/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:32:14 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 09:14:26 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		hash(char *s)
{
	if (ft_strncmp(s, "sp", 2) == 0)
		return (SP);
	else if (ft_strncmp(s, "pl", 2) == 0)
		return (PL);
	else if (ft_strncmp(s, "sq", 2) == 0)
		return (SQ);
	else if (ft_strncmp(s, "tr", 2) == 0)
		return (TR);
	else if (ft_strncmp(s, "cy", 2) == 0)
		return (CY);
	else if (ft_strncmp(s, "cu", 2) == 0)
		return (CU);
	else if (ft_strncmp(s, "py", 2) == 0)
		return (PY);
	return (-1);
}
