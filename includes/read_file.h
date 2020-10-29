/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:28:54 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/25 18:58:25 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include "error.h"
# include "list_all.h"
# include "define.h"
# include "../libft/libft.h"

int		get_next_line(int fd, char **line);
int		hash(char *s);

#endif
