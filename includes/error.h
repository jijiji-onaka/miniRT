/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:26:30 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 09:10:13 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "define.h"
# define ERR_ARG "usage : ./miniRT <scene.rt> || ./miniRT <scene.rt> --save"
# define ERR_FILETAIL "No such file or directory ."
# define ERR_OPEN "Can't open file . "
# define ERR_READ "Failed to read file. "
# define ERR_CLOSE "Failed to close file. "
# define ERR_BMP "Failed to open/create bmp file. "
# define ERR_RT_FORMAT "rt file contains one invalid line . "
# define ERR_RT_FORMAT2 "rt file contains wrong value format . "
# define ERR_RT_FORMAT3 "Invalid fotmat for specific information for object . "
# define ERR_RT_FORMAT4 "rt file contains invalid type identifier . "
# define ERR_RT_FORMAT5 "Each information can be separated by space(s)"
# define ERR_RESOLUTION "rt file can only have one Resolusion . "
# define ERR_RESOLUTION2 "Resolusion is essential . "
# define ERR_RESOLUTION3 "Render size must be greater than 1 . "
# define ERR_AMBIENT "rt file can only have one Ambient lightning . "
# define ERR_MALLOC "MALLOC ERROR : failed to allocate memory . "
# define ERR_VALUE_OVER "Read the error message above . "
# define ERR_CAMERA_VEC "Where are you looking ? (camera normal vecter) "
# define ERR_PL_VEC "Plane cannot exist . "
# define ERR_SQ_VEC "Square cannot exist . "
# define ERR_CY_VEC "Cylinder cannot exist . "
# define ERR_CU_VEC "Cube cannot exist . "
# define ERR_MLX "mlx_init() is returning NULL . "
# define ERR_MLX_WIN "mlx_new_window() is returning NULL . "
# define ERR_MLX_IMG "mlx_new_image() is returning NULL . "

void	exit_put(char *s);
int		exit_perror(char *s);
char	*check_out_of_range(double num, double min, double max, char *obj_elem);
char	*check_vec_range(t_p3 v, double min, double max, char *s);

#endif
