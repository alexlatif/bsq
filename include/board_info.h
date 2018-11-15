/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:43:04 by alatif            #+#    #+#             */
/*   Updated: 2018/11/13 23:43:08 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_INFO_H
# define BOARD_INFO_H

typedef struct		s_board
{
	int				lines;
	char			empty;
	char			obstacle;
	char			full;
	int				no_obs;
	int				width;
	int				error;
}					t_board;

int					check_valid_char(char c, t_board binfo);
t_board				get_binfo(char *fline);

#endif
