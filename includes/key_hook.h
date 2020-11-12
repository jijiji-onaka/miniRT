/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:59:22 by tjinichi          #+#    #+#             */
/*   Updated: 2020/11/12 14:30:50 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H

/*
** SB = square brackets
** BQ = backquote
*/
# include "minirt.h"
# define KEYCODE_A	0
# define KEYCODE_B	11
# define KEYCODE_C	8
# define KEYCODE_D	2
# define KEYCODE_E	14
# define KEYCODE_F	3
# define KEYCODE_G	5
# define KEYCODE_H	4
# define KEYCODE_I	34
# define KEYCODE_J	38
# define KEYCODE_K	40
# define KEYCODE_L	37
# define KEYCODE_M	46
# define KEYCODE_N	45
# define KEYCODE_O	31
# define KEYCODE_P	35
# define KEYCODE_Q	12
# define KEYCODE_R	15
# define KEYCODE_S	1
# define KEYCODE_T	17
# define KEYCODE_U	32
# define KEYCODE_V	9
# define KEYCODE_W	13
# define KEYCODE_X	7
# define KEYCODE_Y	16
# define KEYCODE_Z	6
# define KEYCODE_0	29
# define KEYCODE_1	18
# define KEYCODE_2	19
# define KEYCODE_3	20
# define KEYCODE_4	21
# define KEYCODE_5	23
# define KEYCODE_6	22
# define KEYCODE_7	26
# define KEYCODE_8	28
# define KEYCODE_9	25
# define KEYCODE_MINUS	27
# define KEYCODE_PLUS	24
# define KEYCODE_LEFT_SB	33
# define KEYCODE_RIGHT_SB	30
# define KEYCODE_BS	42
# define KEYCODE_SEMICOLON	41
# define KEYCODE_BQ	39
# define KEYCODE_COMMA	43
# define KEYCODE_PERIOD	47
# define KEYCODE_SLASH	44
# define KEYCODE_F1	122
# define KEYCODE_F2	120
# define KEYCODE_F3	99
# define KEYCODE_F4	118
# define KEYCODE_F5	96
# define KEYCODE_F6	97
# define KEYCODE_F7	98
# define KEYCODE_F8	100
# define KEYCODE_F9	101
# define KEYCODE_F10	109
# define KEYCODE_F11	103
# define KEYCODE_F12	111
# define KEYCODE_F13	105
# define KEYCODE_F14	107
# define KEYCODE_F15	113
# define KEYCODE_F16	106
# define KEYCODE_F17	64
# define KEYCODE_F18	79
# define KEYCODE_F19	80
# define KEYCODE_TAB	48
# define KEYCODE_CAPS_LOCK	57
# define KEYCODE_SP	49
# define KEYCODE_RE	52
# define KEYCODE_LEST_SHIFT	56
# define KEYCODE_RIGHT_SHIFT	60
# define KEYCODE_LEFT_OPTION	58
# define KEYCODE_RIGHT_OPTION	61
# define KEYCODE_LEFT_CONTROL	59
# define KEYCODE_RIGHT_CONTROL	62
# define KEYCODE_LEFT_COMMAND	55
# define KEYCODE_RIGHT_COMMAND	54
# define KEYCODE_DEL	51
# define KEYCODE_ESC	53
# define KEYCODE_LEFT	123
# define KEYCODE_RIGHT	124
# define KEYCODE_UP	126
# define KEYCODE_DOWN	125
# define KEYCODE_FN	63
# define KEYCODE_HOME	116
# define KEYCODE_END	121
# define KEYCODE_PAGE_UP	115
# define KEYCODE_PAGE_DOWN	119

int		key_hook(int keycode, t_info *info);
int		exit_hook(t_info *info);
int		re_paste_hook(t_info *info);

#endif
