/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binfo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:21:54 by alatif            #+#    #+#             */
/*   Updated: 2018/11/14 23:21:57 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINFO_H
# define BINFO_H

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

#endif
