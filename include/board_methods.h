/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_methods.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:43:15 by alatif            #+#    #+#             */
/*   Updated: 2018/11/13 23:43:17 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_METHODS_H
# define BOARD_METHODS_H

# include "board_info.h"

char		**get_board_matrix(int fd, t_board *binfo);
void		print_board(char **board);
char		**solve_matrix(char **matrix, t_board binfo);
char		**solve_empty(char **matrix, t_board binfo);

#endif
